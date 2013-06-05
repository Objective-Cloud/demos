#import <Foundation/Foundation.h>

@interface OCFHTTPResponse : NSObject

#pragma mark - Creating
- (id)initWithURL:(NSURL *)URL
       statusCode:(NSInteger)statusCode
      HTTPVersion:(NSString *)HTTPVersion
     headerFields:(NSDictionary *)headerFields
           reason:(NSString *)reason
     responseData:(NSData *)responseData;

- (id)initWithURL:(NSURL *)URL
       statusCode:(NSInteger)statusCode
     headerFields:(NSDictionary *)headerFields
           reason:(NSString *)reason
     responseData:(NSData *)responseData;

//+ (id)newOKHTTPResponseWithHeaderFields:(NSDictionary *)headerFields
//                           responseData:(NSData *)responseData;

#pragma mark - Properties
@property (nonatomic, strong, readonly) NSURL *URL;
@property (nonatomic, readonly) NSInteger statusCode;
@property (nonatomic, copy, readonly) NSString *HTTPVersion;
@property (nonatomic, copy, readonly) NSDictionary *headerFields;
@property (nonatomic, copy, readonly) NSString *reason;
@property (nonatomic, copy, readonly) NSData *responseData;

@end
