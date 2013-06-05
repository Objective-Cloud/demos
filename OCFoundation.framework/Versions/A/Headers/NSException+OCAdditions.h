#import <Foundation/Foundation.h>

@interface NSException (OCAdditions)

+ (void)raise:(NSString *)name format_oc:(NSString *)format, ...;

@end
