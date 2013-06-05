//
//  OCFJSONEncoder.h
//  OCFoundation
//
//  Created by Amin Negm-Awad on Di.,22.01.13.
//  Copyright (c) 2013 Objective-Cloud.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol OCFJSONEncoder <NSObject>
- (BOOL)encodeObject:(id)object forKey:(NSString*)key error:(NSError**)error;
@end

@protocol OCFJSONDecoder <NSObject>
- (id)decodeObjectOfClass:(Class)class forKey:(NSString*)key error:(NSError**)error;
- (id)decodeStringForKey:(NSString*)key error:(NSError**)error;
- (id)decodeNumberForKey:(NSString*)key error:(NSError**)error;
- (id)decodeArrayWithObjectsOfClass:(Class)class forKey:(NSString*)key error:(NSError**)error;
@end

@interface OCFJSONCoder : NSObject
+ (id)JSONObjectForObject:(id)object error:(NSError**)error;
+ (NSData*)JSONDataForObject:(id)object error:(NSError**)error;
+ (id)objectOfClass:(Class)class forJSONObject:(id)JSONObject error:(NSError**)error;
+ (Class)classObjectForJSONObject:(id)JSONObject error:(NSError**)error;
@end

@interface NSObject(OCFJSONEncoder)
+ (BOOL)usesAutomaticJSONSerialization;
+ (BOOL)usesNSCodingJSONSerialization;
@end
