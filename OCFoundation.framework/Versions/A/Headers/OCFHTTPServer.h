#import <Foundation/Foundation.h>

@class OCFHTTPResponse;
@class OCFHTTPServer;

typedef OCFHTTPResponse *(^CMKHTTPServerRequestHandler)(NSURLRequest *request);
typedef void (^CMKHTTPServerStopHandler)(OCFHTTPServer *HTTPServer);

@interface OCFHTTPServer : NSObject

#pragma mark - Creating
- (id)initWithHostName:(NSString *)hostName
                  port:(in_port_t)port;

- (id)initWithHostName:(NSString *)hostName
                  port:(in_port_t)port
        defaultTimeout:(NSTimeInterval)defaultTimeout
   requestHandlerQueue:(dispatch_queue_t)queue;

@property (nonatomic, readonly) in_port_t port;

#pragma mark - Lifetime
- (void)startWithRequestHandler:(CMKHTTPServerRequestHandler)requestHandler;
- (void)stopWithHandler:(CMKHTTPServerStopHandler)handler;

@end
