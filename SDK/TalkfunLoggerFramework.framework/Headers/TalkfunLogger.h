//
//  TalkfunLogger.h
//  TalkfunMediaPlayerDemo
//
//  Created by LuoLiuyou on 16/7/5.
//  Copyright © 2016年 luoliuyou. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark    日志输出等级
static const int TALKFUN_LOGGER_LEVEL_ALL = 0;
static const int TALKFUN_LOGGER_LEVEL_DEBUG = 1;
static const int TALKFUN_LOGGER_LEVEL_INFO = 2;
static const int TALKFUN_LOGGER_LEVEL_WARN = 3;
static const int TALKFUN_LOGGER_LEVEL_ERROR = 4;
static const int TALKFUN_LOGGER_LEVEL_FATAL = 5;
//static const int TALKFUN_LOGGER_LEVEL_FATAL = 6;
static const int TALKFUN_LOGGER_LEVEL_NONE = 10;


#pragma mark    开始关闭日志
static const int TALKFUN_LOGGER_DISABLE = 0;
static const int TALKFUN_LOGGER_ENABLE = 1;


#pragma mark    日志输出handler
typedef NS_ENUM(NSInteger,TalkfunLoggerHandlerType) {
    TalkfunLoggerHandlerTypeConsole = 1,
    TalkfunLoggerHandlerTypeFile = 2,
    TalkfunLoggerHandlerTypeServer = 3
};

/*
#ifdef DEBUG
 */



#define TalkfunLogger_Debug(token, s, ... ) [[TalkfunLogger shared]accessToken:token print:  [NSString stringWithFormat:@"%s",__FILE__ ] level: TALKFUN_LOGGER_LEVEL_DEBUG func: [NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] line: __LINE__ str: [NSString stringWithFormat:(s), ##__VA_ARGS__]]

#define TalkfunLogger_Info(token, s, ... ) [[TalkfunLogger shared]accessToken:token print:  [NSString stringWithFormat:@"%s",__FILE__ ] level: TALKFUN_LOGGER_LEVEL_INFO func: [NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] line: __LINE__ str: [NSString stringWithFormat:(s), ##__VA_ARGS__]]

#define TalkfunLogger_Warn(token, s, ... ) [[TalkfunLogger shared]accessToken:token print:  [NSString stringWithFormat:@"%s",__FILE__ ] level: TALKFUN_LOGGER_LEVEL_WARN func:[NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] line: __LINE__ str: [NSString stringWithFormat:(s), ##__VA_ARGS__]]
#define TalkfunLogger_Error(token, s, ... ) [[TalkfunLogger shared]accessToken:token print:  [NSString stringWithFormat:@"%s",__FILE__ ] level: TALKFUN_LOGGER_LEVEL_ERROR func: [NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] line: __LINE__ str: [NSString stringWithFormat:(s), ##__VA_ARGS__]]


//#define TalkfunLogger_Fatal( s, ... ) [[TalkfunLogger shared] print:  [NSString stringWithFormat:@"%s",__FILE__ ] level: TALKFUN_LOGGER_LEVEL_FATAL func: [NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] line: __LINE__ str: [NSString stringWithFormat:(s), ##__VA_ARGS__]]

#define TalkfunLogger_SetClassLevel( l ) [[TalkfunLogger shared] setLevel:  [NSString stringWithFormat:@"%s",__FILE__ ] level: (l)]



@interface TalkfunLogger : NSObject {
    NSMutableDictionary* loggers;
}
//是否开启日志
@property (nonatomic) int enable;
//全局日志等级
@property (nonatomic) int globalLogLevel;
//日志输出handler
@property (nonatomic) TalkfunLoggerHandlerType handler;




- (void)accessToken:(NSString*)accessToken print: (NSString*) path level: (int) level func: (NSString*) func line: (int) line str: (NSString*) str;


//- (void) setLevel: (NSString*) theClass level: (int) level;
//- (int) getLevel:(Class)theClass;


+ (TalkfunLogger*) shared;


//accessToken 与云配置的绑定
- (void)config:(NSDictionary *)options accessToken:(NSString*)accessToken  userID:(NSString*)userID  rid:(NSString*)rid   pid:(NSString*)pid  cid:(NSString*)cid userAgent:(NSString*)userAgent sdkVersion:(NSString*)sdkVersion ;

//设置默认配置  点播
- (void)setDefault:(NSString*)access_token  sdkVersion:(NSString *)sdkVersion userID:(NSString*)uid rid:(NSString*)rid   pid:(NSString*)pid  cid:(NSString*)cid userAgent:(NSString*)userAgent channel:(NSString*)channel;


//直播
- (void)config:(NSDictionary*)config userAgent:(NSString*)userAgent sdkVersion:(NSString *)sdkVersion;


@end
