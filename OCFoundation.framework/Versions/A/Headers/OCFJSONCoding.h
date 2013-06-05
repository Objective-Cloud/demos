//
//  OCFJSONCoding.h
//  OCFoundation
//
//  Created by Amin Negm-Awad on Mo.,21.01.13.
//  Copyright (c) 2013 Objective-Cloud.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol OCFJSONEncoder;
@protocol OCFJSONDecoder;

@protocol OCFJSONCoding <NSObject>
- (BOOL)encodeWithJSONEncoder:(id<OCFJSONEncoder>)encoder error:(NSError**)error;
+ (id)newWithJSONDecoder:(id<OCFJSONDecoder>)encoder error:(NSError**)error;
@end

/*
@protocol OCFJSONDictionaryDecoder <NSObject>
//- (id)dictionaryDecoder:(id<OCFJSONDecoder>)decoder shouldDecodeValue:(id)value forKey:(NSString*)key;
- (id)dictionaryDecoder:(id<OCFJSONDecoder>)decoder keyForJSONKey:(id)JSONkey;
- (id)dictionaryDecoder:(id<OCFJSONDecoder>)decoder valueClassForKey:(id)key;
@end
*/