#import <Foundation/Foundation.h>

void ocf_printf(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);
void ocf_printfnl(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);
void ocf_logError(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);
