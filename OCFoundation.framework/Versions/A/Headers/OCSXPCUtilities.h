#import <Foundation/Foundation.h>

id OCSXPCJSONObjectFromXPCObject(xpc_object_t object);

NSNull* OCSXPCNullFromXPCObject(xpc_object_t object);

NSString* OCSXPCStringFromXPCObject(xpc_object_t object);

NSNumber* OCSXPCNumberFromXPCObject(xpc_object_t object);
NSNumber* OCSXPCBoolFromXPCObject(xpc_object_t object);
NSNumber* OCSXPCDoubleFromXPCObject(xpc_object_t object);
NSNumber* OCSXPCInt64FromXPCObject(xpc_object_t object);
NSNumber* OCSXPCUInt64FromXPCObject(xpc_object_t object);


NSArray* OCSXPCArrayFromXPCObject(xpc_object_t object);
NSDictionary* OCSXPCDictionaryFromXPCObject(xpc_object_t object);

NSData* OCSXPCDataFromXPCObject(xpc_object_t object);
