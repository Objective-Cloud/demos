#import <Foundation/Foundation.h>

@interface NSFileManager (OCBAdditions)

#pragma mark - Temporäre Verzeichnisse
- (NSURL *)createTemporaryDirectoryWithIdentifier:(NSString *)identifier
                                        error_ocf:(NSError **)error;

- (NSURL *)createTemporaryUniqueDirectoryAndReturnError_ocf:(NSError **)outError;

@end
