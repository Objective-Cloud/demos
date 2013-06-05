#import <OCAppKit/OCAService.h>

//	Populate and then add this protocol to the class' protocol list, if you want to restrict the publishing of methods to the protocol's methods.
@protocol ServicePublishing <NSObject>
@end

@interface Service : OCAService 
@end
