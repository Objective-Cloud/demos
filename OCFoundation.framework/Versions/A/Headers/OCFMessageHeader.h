#import <Foundation/Foundation.h>

@interface OCFMessageHeader : NSObject

#pragma mark -
#pragma mark Creating Message Headers
- (id)initWithJSONData:(NSData *)JSONData;
- (id)initWithHeaderFields:(NSDictionary *)headerFields;
+ (id)messageHeaderWithZeroContentLength;

#pragma mark -
#pragma mark Properties
@property (readonly) NSUInteger contentLength;
@property (readonly) NSData *JSONData;

@end
