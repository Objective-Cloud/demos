//
//  OCFErrorCodes.h
//  OCFoundation
//
//  Created by Amin Negm-Awad on Mo.,21.01.13.
//  Copyright (c) 2013 Objective-Cloud.com. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const OCFFoundationErrorDomain;

#define STORE_ERROR_AND_RETURN_NIL(passedError) \
	if (error!=NULL) 							\
	{ 											\
		*error = (passedError); 					\
	}											\
	return nil;

enum  OCFErrorCodes : NSInteger {
	OCFErrorCodeNoError = 0x0000,
	
	OCFErrorCodeParser = 0x0200,
	OCFErrorCodeInvalidJSON = 0x0200,
	OCFErrorCodeInvalidNumberOfArguments,
	OCFErrorCodeValueTypeMismatchError,
	OCFErrorCodeNoDeserializationMethod,
	OCFErrorCodeNoSerializationMethod,
	OCFErrorCodeClassDoesNotImplementPublishingProtocol,
	OCFErrorCodeJSONObjectDoesNotMatchPublishingProtocol,
	OCFErrorCodeMethodWithNameNotFoundOnReceiver,
	OCFErrorCodeCloudAppCommunication = 0x0400,
	OCFErrorCodeCloudAppNotFound = 0x0400,
	OCFErrorCodeCloudAppNoConnection,
	
	OCFErrorCodeNoErrorBehindHere
};

@interface NSError (OCFFoundationErrors)
+ (NSError*)valueTypeMismatchErrorWithClass:(Class)class JSONObject:(id)object;
+ (NSError*)noDeserializationMethodForClass:(Class)class;
+ (NSError*)noSerializationMethodForClass:(Class)class;
+ (NSError*)classDoesNotImplementPublishingProtocol:(Class)class;
+ (NSError*)JSONObjectDoesNotMatchPublishingProtocol:(Class)class;
+ (NSError *)methodWithName:(NSString*)methodName notFoundOnReceiver:(id)receiver;
+ (NSError*)cloudAppNotFoundErrorWithBundleIdentifier:(NSString*)bundleIdentifier;
@end