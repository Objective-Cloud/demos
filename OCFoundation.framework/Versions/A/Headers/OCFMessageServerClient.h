#import <Foundation/Foundation.h>

typedef void(^OCFMessageServerClientReplyHandler)(NSDictionary *replyMessage);

@interface OCFMessageServerClient : NSObject

#pragma mark - Creating a Message Server Client
- (id)initWithBaseURL:(NSURL *)baseURL
				 path:(NSString*)path
   defaultTimeout:(NSTimeInterval)defaultTimeout
   operationQueue:(NSOperationQueue *)operationQueue;

- (id)initWithBaseURL:(NSURL *)baseURL path:(NSString*)string;

#pragma mark - Sending Messages and receiving Replies
- (BOOL)sendMessage:(NSDictionary *)message
   withReplyHandler:(OCFMessageServerClientReplyHandler)replyHandler;
- (BOOL)sendMessage:(NSDictionary *)message relativePath:(NSString*)relativePath withReplyHandler:(OCFMessageServerClientReplyHandler)replyHandler;
@end
