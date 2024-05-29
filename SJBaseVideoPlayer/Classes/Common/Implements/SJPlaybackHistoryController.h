
#import <Foundation/Foundation.h>
#import "SJPlaybackHistoryControllerDefines.h"
#import "SJPlaybackRecord.h"
#import <objc/message.h>
NS_ASSUME_NONNULL_BEGIN
@interface SJPlaybackRecord(SJSQLite3Extended)<SJSQLiteTableModelProtocol>

@end

extern SJMediaType const SJMediaTypeVideo;
extern SJMediaType const SJMediaTypeAudio;

@interface SJPlaybackHistoryController : NSObject<SJPlaybackHistoryController>
+ (instancetype)shared;
- (instancetype)initWithPath:(NSString *)path;

- (void)save:(SJPlaybackRecord *)record;

#pragma mark -

- (nullable SJPlaybackRecord *)recordForMedia:(NSInteger)mediaId user:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (nullable NSArray<SJPlaybackRecord *> *)recordsForUser:(NSInteger)userId mediaType:(SJMediaType)mediaType range:(NSRange)range;

- (nullable NSArray<SJPlaybackRecord *> *)recordsForUser:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (nullable NSArray<SJPlaybackRecord *> *)recordsForConditions:(nullable NSArray<SJSQLite3Condition *> *)conditions orderBy:(nullable NSArray<SJSQLite3ColumnOrder *> *)orders range:(NSRange)range;

- (nullable NSArray<SJPlaybackRecord *> *)recordsForConditions:(nullable NSArray<SJSQLite3Condition *> *)conditions orderBy:(nullable NSArray<SJSQLite3ColumnOrder *> *)orders;

#pragma mark -

- (NSUInteger)countOfRecordsForUser:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (NSUInteger)countOfRecordsForConditions:(nullable NSArray<SJSQLite3Condition *> *)conditions;

#pragma mark -

- (void)remove:(NSInteger)media user:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (void)removeAllRecordsForUser:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (void)removeForConditions:(nullable NSArray<SJSQLite3Condition *> *)conditions;
@end
NS_ASSUME_NONNULL_END