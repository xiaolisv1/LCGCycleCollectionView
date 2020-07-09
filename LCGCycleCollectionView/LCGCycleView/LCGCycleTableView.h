//
//  LCGCycleTableView.h
//  LCGCycleCollectionView
//
//  Created by 李传光 on 2019/4/19.
//  Copyright © 2019 李传光. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class LCGCycleTableView ;
@protocol LCGCycleTableViewDataSource <NSObject>
@required
//返回cell个数
- (NSInteger)cycleTableViewCellNumber:(LCGCycleTableView *)cycleTableView ;

//返回cell
-(UITableViewCell *)cycleTableView:(LCGCycleTableView *)cycleTableView cellIndex:(NSInteger)cellIndex cellForRowAtIndex:(NSInteger)index ;

@end

@protocol LCGCycleTableViewDelegate <NSObject>
@optional
//cell点击
-(void)cycleTableView:(LCGCycleTableView *)cycleTableView cellIndex:(NSInteger)cellIndex didSelectRowAtIndex:(NSInteger)index;
//cell大小
-(CGFloat)cycleTableView:(LCGCycleTableView *)cycleTableView heightForRowAtIndex:(NSInteger)index;

@end

@interface LCGCycleTableView : UIView
@property (nonatomic, weak, nullable) id <LCGCycleTableViewDelegate> delegate;
@property (nonatomic, weak, nullable) id <LCGCycleTableViewDataSource> dataSource;
//是否分页 建议使用分页滑动
@property (nonatomic ,assign)IBInspectable BOOL pagingEnabled;
//是否自动滑动
@property (nonatomic ,assign)IBInspectable BOOL autoScroll;
//定时器调用间隔 分页滑动 最小为1
@property (nonatomic ,assign)IBInspectable CGFloat timeInterval ;
//每次移动距离 默认0.5 如果是负数 方向相反;
@property (nonatomic ,assign)IBInspectable CGFloat displacement ;
//分页滑动的时候 每次改变的页数的数量 默认为1
@property (nonatomic ,assign)IBInspectable NSUInteger changePageCount ;

- (void)registerClass:(nullable Class)cellClass forCellReuseIdentifier:(NSString *)identifier ;

- (void)registerNib:(nullable UINib *)nib forCellReuseIdentifier:(NSString *)identifier ;

- (__kindof UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier forCellIndex:(NSInteger)cellIndex ;
//刷新
-(void)reloadData ;

//关闭定时器  （在页面消失的时候调用）
- (void)invalidateTimer ;

//开始定时器  （在页面显示的时候调用）
- (void)setupTimer ;
@end

NS_ASSUME_NONNULL_END
