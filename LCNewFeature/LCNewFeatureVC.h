//
//  Created by 刘超 on 15/4/30.
//  Copyright (c) 2015年 Leo. All rights reserved.
//
//  Email : leoios@sina.com
//  GitHub: http://github.com/LeoiOS
//  如有问题或建议请给我发 Email, 或在该项目的 GitHub 主页 Issues 我, 谢谢:)
//

//  !! warning 必读!! 可删除该警告!!

/**
 *  !!!!!! 必读 !!!!!!
 *
 *  1. 为什么传一个图片名字和图片个数就可以展示所有图片?
 *
 *      Why? No why. 按以下要求命名图片即可:
 *      第一张图: `<name>_1@2x.png`
 *      第二张图: `<name>_2@2x.png`
 *      ...
 *
 *      如:
 *      `NewFeature_1@2x.png`   将作为第一张图展示
 *      `NewFeature_2@2x.png`   将作为第二张图展示
 *      ...
 *
 *
 *  2. 怎么适配iPhone5\5s, iPhone6, iPhone6Plus?
 *
 *      iPhone5\5s的图片请在名字后面拼接`_iphone5`;
 *      iPhone6的图片请在名字后面拼接`_iphone6`;
 *      iPhone6Plus的图片请在名字后面拼接`_iphone6p`;
 *
 *      如:
 *      `NewFeature_1@2x.png`           将展示在iPhone4/4S上
 *      `NewFeature_1_iphone5@2x.png`   将展示在iPhone5/5S上
 *      `NewFeature_1_iphone6@2x.png`   将展示在iPhone6上
 *      `NewFeature_1_iphone6p@2x.png`  将展示在iPhone6Plus上
 *
 *
 *  3. 如果想变更状态栏的样式, 打开项目的Info.plist, 先添加下列键值对, 然后statusBarStyle属性才会生效:
 *      
 *      Key  :  View controller-based status bar appearance
 *      Value:  NO
 *
 *
 *  4. 如果还有问题或者建议, 请联系我, 我也想做的更好! 联系方式在顶部:)
 */

#import <UIKit/UIKit.h>

// 屏幕尺寸
#define SCREEN_SIZE [UIScreen mainScreen].bounds.size

/**
 *  完成新特性界面展示后的block回调
 */
typedef void (^finishBlock)();

/**
 *  状态栏样式
 */
typedef NS_ENUM(NSInteger, LCStatusBarStyle) {
    /** 黑色 */
    LCStatusBarStyleBlack,
    /** 白色 */
    LCStatusBarStyleWhite,
    /** 隐藏 */
    LCStatusBarStyleNone
};

@interface LCNewFeatureVC : UIViewController


#pragma mark - 属性 Properties

/**
 *  当前点(分页控制器)的颜色
 */
@property (nonatomic, strong) UIColor *pointCurrentColor;
/**
 *  其他点(分页控制器)的颜色
 */
@property (nonatomic, strong) UIColor *pointOtherColor;
/**
 *  状态栏样式, 请先参考`必读`第3条设置
 */
@property (nonatomic, assign) LCStatusBarStyle statusBarStyle;

#pragma mark - 方法 Methods

/**
 *  是否显示新特性视图控制器, 对比版本号得知
 */
+ (BOOL)shouldShowNewFeature;

/**
 *  初始化新特性视图控制器, 类方法
 *
 *  @param imageName 图片名, 请将原图名称修改为该格式: `<imageName>_1`, `<imageName>_2`... 如: `NewFeature_1@2x.png`
 *
 *  @param imageCount 图片个数
 *
 *  @param showPageControl 是否显示分页控制器
 *
 *  @param enterButton 进入主界面的按钮
 *
 *  @return 初始化的控制器实例
 */
+ (instancetype)newFeatureWithImageName:(NSString *)imageName
                             imageCount:(NSInteger)imageCount
                        showPageControl:(BOOL)showPageControl
                            enterButton:(UIButton *)enterButton;

/**
 *  初始化新特性视图控制器, 实例方法
 *
 *  @param imageName 图片名, 请将原图名称修改为该格式: `<imageName>_1`, `<imageName>_2`... 如: `NewFeature_1@2x.png`
 *
 *  @param imageCount 图片个数
 *
 *  @param showPageControl 是否显示分页控制器
 *
 *  @param enterButton 进入主界面的按钮
 *
 *  @return 初始化的控制器实例
 */
- (instancetype)initWithImageName:(NSString *)imageName
                       imageCount:(NSInteger)imageCount
                  showPageControl:(BOOL)showPageControl
                      enterButton:(UIButton *)enterButton;

/**
 *  初始化新特性视图控制器, 类方法
 *
 *  @param imageName 图片名, 请将原图名称修改为该格式: `<imageName>_1`, `<imageName>_2`... 如: `NewFeature_1@2x.png`
 *
 *  @param imageCount 图片个数
 *
 *  @param showPageControl 是否显示分页控制器
 *
 *  @param finishBlock 完成新特性界面展示后的回调
 *
 *  @return 初始化的控制器实例
 */
+ (instancetype)newFeatureWithImageName:(NSString *)imageName
                             imageCount:(NSInteger)imageCount
                        showPageControl:(BOOL)showPageControl
                            finishBlock:(finishBlock)finishBlock;

/**
 *  初始化新特性视图控制器, 实例方法
 *
 *  @param imageName 图片名, 请将原图名称修改为该格式: `<imageName>_1`, `<imageName>_2`... 如: `NewFeature_1@2x.png`
 *
 *  @param imageCount 图片个数
 *
 *  @param showPageControl 是否显示分页控制器
 *
 *  @param finishBlock 完成新特性界面展示后的回调
 *
 *  @return 初始化的控制器实例
 */
- (instancetype)initWithImageName:(NSString *)imageName
                       imageCount:(NSInteger)imageCount
                  showPageControl:(BOOL)showPageControl
                      finishBlock:(finishBlock)finishBlock;

@end
