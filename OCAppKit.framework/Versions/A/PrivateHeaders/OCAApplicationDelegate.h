#import <Cocoa/Cocoa.h>

@protocol OCAApplicationDelegatePublishing <NSObject>
- (NSArray*)servicesList;
- (NSArray*)version;
@end

@interface OCAApplicationDelegate : NSObject <NSApplicationDelegate, OCAApplicationDelegatePublishing>
@end
