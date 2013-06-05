#import <Foundation/Foundation.h>

@interface NSObject (OCSXPCAdditions)

#pragma mark -
#pragma mark Getting an xpc_value from an Object
- (xpc_object_t)XPCObjectValue_ocs;

@end
