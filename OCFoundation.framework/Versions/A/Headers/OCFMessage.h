#import <Foundation/Foundation.h>

@class OCFMessageHeader;
@interface OCFMessage : NSObject

#pragma mark -
#pragma mark Creating Messages
- (id)initWithHeader:(OCFMessageHeader *)header
            JSONData:(NSData *)JSONData;

- (id)initWithJSONData:(NSData *)JSONData;


#pragma mark -
#pragma mark Getting Message Properties
@property (readonly) NSData *headerAndMessageData;

#pragma mark -
#pragma mark Sending
//- (BOOL)sendToHostWit

@end