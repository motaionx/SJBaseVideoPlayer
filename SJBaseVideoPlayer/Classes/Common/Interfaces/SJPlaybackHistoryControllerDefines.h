
#ifndef SJPlaybackHistoryControllerDefines_h
#define SJPlaybackHistoryControllerDefines_h
#if __has_include(<SJUIKit/SJSQLite3.h>)
#import <SJUIKit/SJSQLite3+QueryExtended.h>
#else
#import "SJSQLite3+QueryExtended.h"
#endif

#import "SJVideoPlayerURLAsset.h"
@protocol SJPlaybackRecord;

NS_ASSUME_NONNULL_BEGIN

typedef NSString *SJMediaType; // 目前存在两种类型, 分别是: `SJMediaTypeVideo`(视频) 与 `SJMediaTypeAudio`(音乐)
extern SJMediaType const SJMediaTypeVideo;
extern SJMediaType const SJMediaTypeAudio;

@protocol SJPlaybackHistoryController <NSObject>

- (void)save:(id<SJPlaybackRecord>)record;

#pragma mark -

- (nullable id<SJPlaybackRecord>)recordForMedia:(NSInteger)mediaId user:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (nullable NSArray<id<SJPlaybackRecord>> *)recordsForUser:(NSInteger)userId mediaType:(SJMediaType)mediaType range:(NSRange)range;

- (nullable NSArray<id<SJPlaybackRecord>> *)recordsForUser:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (nullable NSArray<id<SJPlaybackRecord>> *)recordsForConditions:(nullable NSArray<SJSQLite3Condition *> *)conditions orderBy:(nullable NSArray<SJSQLite3ColumnOrder *> *)orders range:(NSRange)range;

- (nullable NSArray<id<SJPlaybackRecord>> *)recordsForConditions:(nullable NSArray<SJSQLite3Condition *> *)conditions orderBy:(nullable NSArray<SJSQLite3ColumnOrder *> *)orders;

#pragma mark -

- (NSUInteger)countOfRecordsForUser:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (NSUInteger)countOfRecordsForConditions:(nullable NSArray<SJSQLite3Condition *> *)conditions;

#pragma mark -

- (void)remove:(NSInteger)media user:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (void)removeAllRecordsForUser:(NSInteger)userId mediaType:(SJMediaType)mediaType;

- (void)removeForConditions:(nullable NSArray<SJSQLite3Condition *> *)conditions;
@end

@protocol SJPlaybackRecord <NSObject>
@property (nonatomic, readonly) NSInteger mediaId;
@property (nonatomic, readonly) NSInteger userId;
@property (nonatomic, readonly) SJMediaType mediaType;
@property (nonatomic, readonly) NSTimeInterval position; ///< 上次观看到的位置
@property (nonatomic, readonly) NSTimeInterval createdTime;
@property (nonatomic, readonly) NSTimeInterval updatedTime;
@end
NS_ASSUME_NONNULL_END

#endif /* SJPlaybackHistoryControllerDefines_h */