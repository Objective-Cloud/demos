#import <Foundation/Foundation.h>


typedef void(^OCFMessageServerReplyBlock)(NSDictionary *response);

@class OCFMessageServer_Old;
@protocol OCFMessageServerDelegate <NSObject>

    @required
    - (BOOL)messageServer:(OCFMessageServer_Old *)messageServer
        didReceiveMessage:(NSDictionary *)message
                    error:(NSError **)error
               replyBlock:(OCFMessageServerReplyBlock)replyBlock;

@end
