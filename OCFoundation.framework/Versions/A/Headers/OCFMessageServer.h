#import <Foundation/Foundation.h>

@class OCFMessageServer;

typedef NSDictionary *(^OCFMessageServerMessageHandler)(id receiver, NSDictionary *inputMessage);
typedef void (^OCFMessageServerStopHandler)(OCFMessageServer *messageServer);

@interface OCFMessageServer : NSObject

#pragma mark - Creating a Message Server
- (id)initWithHostName:(NSString *)hostName
                  port:(short)port
        defaultTimeout:(NSTimeInterval)defaultTimeout
                 queue:(dispatch_queue_t)queue;

- (id)initWithHostName:(NSString *)hostName
                  port:(short)port;

- (in_port_t)port;

#pragma mark - Lifetime
- (void)startWithMessageHandler:(OCFMessageServerMessageHandler)messageHandler;
- (void)stopWithHandler:(OCFMessageServerStopHandler)stopHandler;

#pragma mark - Configuration
//	Setting this option changes the behaviour for testing with curl
//	1. Every content type beginning with application/ is accepted, esp. the curl default application/x-www-form-urlencoded
//	2. Responses are pretty printed (NSJSONWritingPrettyPrinted)
//	3. Responses get anadditional \n at the end to force a newline at the terminal
@property (nonatomic) BOOL communicatesWithConsole;
@end
