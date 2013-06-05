//
//  OCSCloudAppID.h
//  OCFoundation
//
//  Created by Amin Negm-Awad on Fr.,01.02.13.
//  Copyright (c) 2013 Objective-Cloud.com. All rights reserved.
//

// This class simply creates an identifer, which specifies every running instance in the whole infrastructure;
#import <Foundation/Foundation.h>

@protocol OCFMessageTargetPublishing <NSObject>
@property (nonatomic, copy, readonly) NSString *bundleIdentifier;
@property (nonatomic, copy, readonly) NSString *hostName;
@end

@interface OCFMessageTarget : NSObject < NSCopying, OCFMessageTargetPublishing >
@property (nonatomic, copy, readonly) NSString *bundleIdentifier;
@property (nonatomic, copy, readonly) NSString *hostName;
@property (nonatomic, readonly) pid_t processIdentifier;
@property (nonatomic, strong, readonly) id address;

- (BOOL)isEqualToCloudAppID:(OCFMessageTarget*)cloudAppID;

+ (id)newMessageTargetWithBundleIdentifier:(NSString*)bundleIdentifier
								  hostName:(NSString*)hostName
						 processIdentifier:(pid_t)processIdentifer
								   address:(id)adress;
@end
