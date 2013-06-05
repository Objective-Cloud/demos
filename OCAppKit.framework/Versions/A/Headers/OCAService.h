#import <Foundation/Foundation.h>

@protocol OCAService <NSObject>
+ (NSDictionary*)methodDescriptions;
@end

@interface OCAService : NSObject <OCAService>
@end

extern int OCAApplicationMain(int argc, const char *argv[]);

extern void OCALog( NSString* format, ... ) NS_FORMAT_FUNCTION(1,2);