//
//  OCFDispatcher.h
//  OCFoundation
//
//  Created by Amin Negm-Awad on Mo.,28.01.13.
//  Copyright (c) 2013 Objective-Cloud.com. All rights reserved.
//

//	Partial abstract base class for dispatching a message
//
//	-dispatchRequest:toReceiver:error: gets a request dictionary and a receiver id.
//	(Actually an url.) The receiver id is translated into a bundle identifier.
//	if the bundle identifer matches the localBundleIdentifier, a method of
//	localService is executed, whose selector matches the selector in the
//	message using NSInvocation.
//	If the bundle identifier does not match the localBundleIdentifier, a list
//	of potential receivers, set with -
//	setAddress:forRemoteServiceWithBundleIdentifier:, looked-up. If a entry is
//	found, -deliverRequest:toReceiver:withAddress:error: is called. This method is
//	overwritten in subclasses for delivering the request through different
//	communication channels (HTTP, XPC, …)

@class OCFMessageTarget;

#import <Foundation/Foundation.h>
@interface OCFDispatcher : NSObject

//	Diese Ebene
@property (nonatomic, readonly, strong) id localService;
@property (nonatomic, readonly, copy) NSDictionary *localMethods;

@property (nonatomic, strong) NSString *localBundleIdentifier;

#pragma mark - Message Targets
@property (nonatomic, readonly) NSArray *targetIdentifiers;
- (void)addTarget:(OCFMessageTarget*)target forIdentifier:(NSString*)identifier;
- (void)removeTarget:(OCFMessageTarget*)target;
- (NSOrderedSet*)targetsForIdentifier:(NSString*)identifier;
- (OCFMessageTarget*)targetForBundleIdentifier:(NSString*)bundleIdentifier
							 processIdentifier:(pid_t)processIdentifier;

#pragma mark - Dispatching
//	Dispatch
//	This method is called from any interested in dispatching a request.
//	If dispatching failed, retval == nil and error contains a error message, probably with a key underlying error in the user-info.
- (NSDictionary*)dispatchRequest:(NSDictionary*)request toReceiver:(NSString*)receiver error:(NSError **)error;

//	Overwrite this method to deliver the request to somebody else
//	Do not call this method directly.
- (NSDictionary*)deliverRequest:(NSDictionary*)request toReceiver:(NSString*)receiver withAddress:(id)address error:(NSError**)error;

//	Executes the request on the local service
- (NSDictionary*)executeRequest:(NSDictionary*)request;

#pragma mark – Introsepction
//- (NSArray*)parameterClassesForMethodWithSelector:(SEL)selector inTarget:(id)target;

#pragma mark - Debugging
@property (nonatomic) BOOL addsExecutionTimeForResponse;
@property (nonatomic) BOOL addsProcessIdentifierToResponse;

+ (id)newDispatcherWithLocalService:(id)localService;
@end

