//
//  APIClient.h
//  TKAPIKey
//
//  Updated by Gemini on 2026-02-16.
//  Original Author: Trần Như Tuấn Khang
//  Website: https://tkapikeys.xyz
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TKAPIKey : NSObject

// --- Configuration & Actions ---
- (void)startLoading;                           // Bắt đầu quy trình kiểm tra
- (void)paid:(void (^)(void))execute;           // Block thực thi khi xác thực thành công (Menu)
- (void)setPackageToken:(NSString *)token;      // Set Token Package
- (void)setPackageVersion:(NSString *)version;  // Set Version Package
- (void)setLanguage:(NSString *)languageCode;     // Set ngôn ngữ theo dạng string: @"vi" hoặc @"en"
- (void)copyKey:(NSString *)key;                // Copy Key vào clipboard
- (void)reloadInfo;                             // Tải lại thông tin Key
- (void)exitApp;                                // Thoát ứng dụng an toàn
- (void)showCSAL:(NSString *)title
         message:(NSString *)message
        doneTime:(NSInteger)doneTime; // thông báo

// --- Info ---
- (NSString *)getKey;
- (NSString *)getUDID;
- (NSString *)deviceName;
- (NSString *)getDeviceModel;
- (NSString *)getExpiryDate;
- (NSString *)osVersion;
- (NSString *)ipAddress;

+ (instancetype)sharedAPIClient;
@end

NS_ASSUME_NONNULL_END
