
#import <UIKit/UIKit.h>
@protocol SJPlayModelPlayerSuperview, SJPlayModelNestedView;

NS_ASSUME_NONNULL_BEGIN
@interface SJPlayModel: NSObject
/**
 The selector of `playerSuperView`, the playModel will be get superview through the selector.
 
 \code
    /// case 1:
    ///
    /// `playerSuperView` => UICollectionViewCell => UICollectionView
    ///
    /// The selector is @selector(playerSuperview);
    @interface YourCollectionViewCell ()
    @property (nonatomic, strong) UIView *playerSuperview;
    @end
 
    /// case 2:
    ///
    /// `playerSuperview` => UITableViewCell => UITableView
    ///
    /// The selector is @selector(playerSuperview2);
    @interface YourTableViewCell ()
    @property (nonatomic, strong) UIView *playerSuperview2;
    @end

    /// case 3:
    ///
    /// `playerSuperview` => UIScrollView
    ///
    /// The selector is @selector(playerSuperview);
    @interface YourScrollView ()
    @property (nonatomic, strong) UIView *playerSuperview;
    @end
 
    /// case 4:
    ///
    /// `playerSuperview` => TableHeaderView
    ///
    /// The selector is @selector(playerSuperview);
    @interface YourTableHeaderView ()
    @property (nonatomic, strong) UIView *playerSuperview;
    @end
    _tableView.tableHeaderView = YourTableHeaderView;
 
    /// case 5:
    ///
    /// `playerSuperview` => TableViewSectionHeaderFooterView
    ///
    /// The selector is @selector(playerSuperview);
    @interface YourTableViewSectionHeaderFooterView
    @property (nonatomic, strong) UIView *playerSuperview;
    @end
    - (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section {
        return YourTableViewSectionHeaderFooterView;
    }

    /// more ..

 \endcode
 */
@property (nonatomic, nullable) SEL superviewSelector;

/**
 The nextPlayModel is used in nested view hierarchy. Specify nested view with `scrollViewSelector`.
 
 \code
    // view hierarchy case 1:
    //
    // `playerSuperView`(1) => UICollectionViewCell(2) => `UICollectionView(nested view)`(3) => UICollectionViewCell(4) => UICollectionView(5)
    @interface YourCollectionViewCell () // (2)
    @property (nonatomic, strong) UIView *playerSuperview; // (1)
    @end

    @interface YourCollectionViewCell () // (4)
    @property (nonatomic, strong) UICollectionView *collectionView; // (3)
    @end
 
    SJPlayModel *next = [SJPlayModel playModelWithCollectionView:(5) indexPath:indexPath for (4)];
    next.scrollViewSelector = @selector(collectionView); // (3)

    SJPlayModel *one = [SJPlayModel playModelWithCollectionView:(3) indexPath:indexPath for (2)];
    one.superviewSelector = @selector(playerSuperview); // (1)
    one.nextPlayModel = next;
 
    // view hierarchy case 2:
    //
    // `playerSuperView`(1) => UICollectionViewCell(2) => `UICollectionView(nested view)`(3) => UITableViewCell(4) => UITableView(5)
    @interface YourCollectionViewCell () // (2)
    @property (nonatomic, strong) UIView *playerSuperview; // (1)
    @end

    @interface YourTableViewCell () // (4)
    @property (nonatomic, strong) UICollectionView *collectionView; // (3)
    @end

    SJPlayModel *next = [SJPlayModel playModelWithTableView:(5) indexPath:indexPath for (4)];
    next.scrollViewSelector = @selector(collectionView); // (3)

    SJPlayModel *one = [SJPlayModel playModelWithCollectionView:(3) indexPath:indexPath for (2)];
    one.superviewSelector = @selector(playerSuperview); // (1)
    one.nextPlayModel = next;
 \endcode
*/
@property (nonatomic, strong, nullable) __kindof SJPlayModel *nextPlayModel;

/**
 The selector of `scrollView` in the below cases.
 
 \code
    // view hierarchy case 1:
    //
    // `playerSuperView`(1) => UICollectionViewCell(2) => `UICollectionView(nested view)`(3) => UICollectionViewCell(4) => UICollectionView(5)
    @interface YourCollectionViewCell () // (2)
    @property (nonatomic, strong) UIView *playerSuperview; // (1)
    @end

    @interface YourCollectionViewCell () // (4)
    @property (nonatomic, strong) UICollectionView *collectionView; // (3)
    @end

    SJPlayModel *next = [SJPlayModel playModelWithCollectionView:(5) indexPath:indexPath for (4)];
    next.scrollViewSelector = @selector(collectionView); // (3)

    SJPlayModel *one = [SJPlayModel playModelWithCollectionView:(3) indexPath:indexPath for (2)];
    one.superviewSelector = @selector(playerSuperview); // (1)
    one.nextPlayModel = next;

    // view hierarchy case 2:
    //
    // `playerSuperView`(1) => UICollectionViewCell(2) => `UICollectionView(nested view)`(3) => UITableViewCell(4) => UITableView(5)
    @interface YourCollectionViewCell () // (2)
    @property (nonatomic, strong) UIView *playerSuperview; // (1)
    @end

    @interface YourTableViewCell () // (4)
    @property (nonatomic, strong) UICollectionView *collectionView; // (3)
    @end

    SJPlayModel *next = [SJPlayModel playModelWithTableView:(5) indexPath:indexPath for (4)];
    next.scrollViewSelector = @selector(collectionView); // (3)

    SJPlayModel *one = [SJPlayModel playModelWithCollectionView:(3) indexPath:indexPath for (2)];
    one.superviewSelector = @selector(playerSuperview); // (1)
    one.nextPlayModel = next;
 \endcode
 */
@property (nonatomic, nullable) SEL scrollViewSelector;

@property (nonatomic) UIEdgeInsets playableAreaInsets;

#pragma mark - UIView

- (instancetype)init;

#pragma mark - UIScrollView

+ (instancetype)playModelWithScrollView:(__weak UIScrollView *)scrollView;
+ (instancetype)playModelWithScrollView:(__weak UIScrollView *)scrollView superviewSelector:(SEL)superviewSelector;

#pragma mark - UITableView

+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView indexPath:(NSIndexPath *)indexPath;
+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView indexPath:(NSIndexPath *)indexPath superviewSelector:(SEL)superviewSelector;

+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView tableHeaderView:(__weak UIView *)tableHeaderView;
+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView tableHeaderView:(__weak UIView *)tableHeaderView superviewSelector:(SEL)superviewSelector;

+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView tableFooterView:(__weak UIView *)tableFooterView;
+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView tableFooterView:(__weak UIView *)tableFooterView superviewSelector:(SEL)superviewSelector;

+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView inHeaderForSection:(NSInteger)section;
+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView inHeaderForSection:(NSInteger)section superviewSelector:(SEL)superviewSelector;

+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView inFooterForSection:(NSInteger)section;
+ (instancetype)playModelWithTableView:(__weak UITableView *)tableView inFooterForSection:(NSInteger)section superviewSelector:(SEL)superviewSelector;


#pragma mark - UICollectionView

+ (instancetype)playModelWithCollectionView:(__weak UICollectionView *)collectionView indexPath:(NSIndexPath *)indexPath;
+ (instancetype)playModelWithCollectionView:(__weak UICollectionView *)collectionView indexPath:(NSIndexPath *)indexPath superviewSelector:(SEL)superviewSelector;

+ (instancetype)playModelWithCollectionView:(UICollectionView *__weak)collectionView inHeaderForSection:(NSInteger)section;
+ (instancetype)playModelWithCollectionView:(UICollectionView *__weak)collectionView inHeaderForSection:(NSInteger)section superviewSelector:(SEL)superviewSelector;

+ (instancetype)playModelWithCollectionView:(UICollectionView *__weak)collectionView inFooterForSection:(NSInteger)section;
+ (instancetype)playModelWithCollectionView:(UICollectionView *__weak)collectionView inFooterForSection:(NSInteger)section superviewSelector:(SEL)superviewSelector;

#pragma mark -


- (BOOL)isPlayInScrollView;
- (nullable UIView<SJPlayModelPlayerSuperview> *)playerSuperview;
- (nullable __kindof UIScrollView *)inScrollView;
- (nullable NSIndexPath *)indexPath;
- (NSInteger)section;

@property (nonatomic) NSUInteger superviewTag;
@end


__deprecated_msg("use `playModel.superviewSelector`;")
@protocol SJPlayModelPlayerSuperview 

@end

__deprecated_msg("use `playModel.nextPlayModel` and `playModel.scrollViewSelector`;")
@protocol SJPlayModelNestedView

@end





















#pragma mark -  以下内容已过期, 将来可能会删除


@interface SJPlayModel (SJDeprecated)

+ (instancetype)UIViewPlayModel __deprecated_msg("use `SJPlayModel.alloc.init`!");

+ (instancetype)UITableViewCellPlayModelWithPlayerSuperviewTag:(NSInteger)playerSuperviewTag
                                                   atIndexPath:(__strong NSIndexPath *)indexPath
                                                     tableView:(__weak UITableView *)tableView __deprecated_msg("use `playModelWithTableView:indexPath`!");

+ (instancetype)UICollectionViewCellPlayModelWithPlayerSuperviewTag:(NSInteger)playerSuperviewTag
                                                        atIndexPath:(__strong NSIndexPath *)indexPath
                                                     collectionView:(__weak UICollectionView *)collectionView __deprecated_msg("use `playModelWithCollectionView:indexPath`!");



+ (instancetype)UITableViewHeaderViewPlayModelWithPlayerSuperview:(__weak UIView *)playerSuperview
                                                        tableView:(__weak UITableView *)tableView __deprecated_msg("use `playModelWithTableView:tableHeaderView`!");

+ (instancetype)UITableViewHeaderFooterViewPlayModelWithPlayerSuperviewTag:(NSInteger)playerSuperviewTag
                                                                        inSection:(NSInteger)section
                                                                         isHeader:(BOOL)isHeader    // 是否是Header, 如果是传YES, 如果是Footer传NO
                                                                        tableView:(__weak UITableView *)tableView __deprecated_msg("use `playModelWithTableView:tableFooterView`!");

+ (instancetype)UICollectionViewNestedInUITableViewHeaderViewPlayModelWithPlayerSuperviewTag:(NSInteger)playerSuperviewTag
                                                                                 atIndexPath:(NSIndexPath *)indexPath
                                                                              collectionView:(__weak UICollectionView *)collectionView
                                                                                   tableView:(__weak UITableView *)tableView __deprecated_msg("use `nextPlayModel`!");

+ (instancetype)UICollectionViewNestedInUITableViewCellPlayModelWithPlayerSuperviewTag:(NSInteger)playerSuperviewTag
                                                                           atIndexPath:(__strong NSIndexPath *)indexPath
                                                                     collectionViewTag:(NSInteger)collectionViewTag
                                                             collectionViewAtIndexPath:(__strong NSIndexPath *)collectionViewAtIndexPath
                                                                             tableView:(__weak UITableView *)tableView __deprecated_msg("use `nextPlayModel`!");

+ (instancetype)UICollectionViewNestedInUICollectionViewCellPlayModelWithPlayerSuperviewTag:(NSInteger)playerSuperviewTag
                                                                                atIndexPath:(__strong NSIndexPath *)indexPath
                                                                          collectionViewTag:(NSInteger)collectionViewTag
                                                                  collectionViewAtIndexPath:(__strong NSIndexPath *)collectionViewAtIndexPath
                                                                         rootCollectionView:(__weak UICollectionView *)rootCollectionView __deprecated_msg("use `nextPlayModel`!");
@end

@protocol SJPlayerDefaultSelectors <NSObject>
@property (nonatomic, readonly) id playerSuperview;
@property (nonatomic, readonly) id collectionView;
@end
NS_ASSUME_NONNULL_END