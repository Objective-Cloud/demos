#import "Service.h"

#import <Foundation/Foundation.h>
#import <OCFoundation/OCFoundation.h>
#import <OCFoundation/OCFJSONCoder.h>
#import <CoreLocation/CoreLocation.h>

#import <QuartzCore/QuartzCore.h>
#import <Quartz/Quartz.h>

@implementation Service
+ (NSDictionary*)dictionary:(NSDictionary*)dictionary withRemovedKey:(NSString*)key
{
    OCALog(@"in: %@", dictionary);
    OCALog(@"key: %@", key);

	NSMutableDictionary *mutable = [dictionary mutableCopy];
	[mutable removeObjectForKey:key];
	[NSThread sleepForTimeInterval:1.0];
    OCALog(@"out: %@", mutable);
	return mutable;
}


+ (NSString *)nameOfLocationAtLatitude:(NSNumber *)latitude
                             longitude:(NSNumber *)longitude {
    CLLocationDegrees latitudeValue = [latitude doubleValue];
    CLLocationDegrees longitudeValue = [longitude doubleValue];
    
    CLLocation *location = [[CLLocation alloc] initWithLatitude:latitudeValue
                                                      longitude:longitudeValue];
    
    CLGeocoder *reverseGeocoder = [[CLGeocoder alloc] init];
    
    __block NSString *nameOfLocation = nil;
    dispatch_semaphore_t holdOn = dispatch_semaphore_create(0);
    
    [reverseGeocoder reverseGeocodeLocation:location
                          completionHandler:^(NSArray *placemarks, NSError *error)
     {
         CLPlacemark *placemark = [placemarks lastObject];
         if(placemark)
         {
             nameOfLocation = placemark.name;
         }
         dispatch_semaphore_signal(holdOn);
     }];
    
    dispatch_semaphore_wait(holdOn, DISPATCH_TIME_FOREVER);
    
    return nameOfLocation;
}

//
+ (NSDictionary *)searchResultOfPDFDocumentAtURL:(NSString *)documentURLStringValue
                                     searchToken:(NSString *)searchToken
{
    NSURL *documentURL = [NSURL URLWithString:documentURLStringValue];
    PDFDocument *document = [[PDFDocument alloc] initWithURL:documentURL];
    NSArray *selections = [document findString:searchToken
                                   withOptions:NSCaseInsensitiveSearch];
    
    NSMutableDictionary *response = [NSMutableDictionary dictionary];
    
    for(PDFSelection *selection in selections)
    {
        PDFPage *page = selection.pages[0]; // get the first Page
        
        NSNumber *matchCount = response[page.label];
        
        if(matchCount == nil)
        {
            matchCount = @(1);
        }
        else
        {
            matchCount = @(matchCount.unsignedIntegerValue + 1);
        }
        response[page.label] = matchCount;
    }
    
    return response;
}

+ (NSArray *)findText:(NSString *)text inAdventuresOfHuckleberryFinnAndIncludeTextPassagesWithMatches:(NSNumber *)includePassages {
    NSBundle *mainBundle = [NSBundle mainBundle];
    NSURL *URL = [mainBundle URLForResource:@"Adventures_of_Huckleberry_Finn_by_Mark_Twain" withExtension:@"pdf"];
    PDFDocument *document = [[PDFDocument alloc] initWithURL:URL];

    NSArray *selections = [document findString:text
                                   withOptions:NSCaseInsensitiveSearch];
    
    NSMutableArray *response = [NSMutableArray new];
    
    for(PDFSelection *selection in selections)
    {
        PDFPage *page = selection.pages[0]; // get the first Page
        NSMutableDictionary *match = [NSMutableDictionary new];
        
        match[@"page"] = page.label;
        
        if(includePassages.boolValue) {
            [selection extendSelectionAtStart:140];
            [selection extendSelectionAtEnd:140];
            match[@"passage"] = selection.string;
        }
        [response addObject:match];
    }
    
    return response;
}

+ (NSArray *)facesInImageAtURL:(NSString *)URLStringValue
         includeFacialFeatures:(NSNumber *)includeFacialFeatures {
    NSURL *imageURL = [NSURL URLWithString:URLStringValue];
    CIImage *image = [CIImage imageWithContentsOfURL:imageURL];
    NSDictionary *options = @{ CIDetectorAccuracy : CIDetectorAccuracyLow };
    
    CIDetector *detector = [CIDetector detectorOfType:CIDetectorTypeFace
                                              context:nil
                                              options:options];
    
    NSArray *faceFeatures = [detector featuresInImage:image
                                              options:nil];
    
    BOOL includeFacialFeaturesValue = includeFacialFeatures.boolValue;
    
    NSMutableArray *detectedFaces = [NSMutableArray array];
    for(CIFeature *feature in faceFeatures)
    {
        NSMutableDictionary *featureJSONRepresentation = [@{} mutableCopy];
        featureJSONRepresentation[@"type"] = feature.type;
        featureJSONRepresentation[@"bounds"] = NSStringFromRect(NSRectFromCGRect(feature.bounds));
  
        if([feature.type isEqualToString:CIFeatureTypeFace] && includeFacialFeaturesValue) {
            CIFaceFeature *faceFeature = (CIFaceFeature *)feature;
            if(faceFeature.hasLeftEyePosition) {
                featureJSONRepresentation[@"leftEyePosition"] = NSStringFromPoint(faceFeature.leftEyePosition);
            }
            if(faceFeature.hasRightEyePosition) {
                featureJSONRepresentation[@"rightEyePosition"] = NSStringFromPoint(faceFeature.rightEyePosition);
            }
            if(faceFeature.hasMouthPosition) {
                featureJSONRepresentation[@"mouthPosition"] = NSStringFromPoint(faceFeature.mouthPosition);
            }
        }
        
        [detectedFaces addObject:featureJSONRepresentation];
    }
    return detectedFaces;

}

+ (NSArray *)facesInImageAtURL:(NSString *)URLStringValue {
    return [self facesInImageAtURL:URLStringValue includeFacialFeatures:@NO];
}

@end