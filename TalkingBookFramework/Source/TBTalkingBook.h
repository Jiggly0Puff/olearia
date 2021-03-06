//
//  TBTalkingBook.h
//  TalkingBook Framework
//
//  Created by Kieren Eaton on 5/05/08.
//  Copyright 2008 BrainBender Software. All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <QTKit/QTTime.h>
#import "TBPluginInterface.h"

@class TBInfoController;
@class TBBookData;

typedef enum 
{
	levelNavigationControlMode,
	pageNavigationControlMode,
	phraseNavigationControlMode,
	sentenceNavigationControlMode,
	wordNavigationControlMode
} levelControlMode;

@interface TBTalkingBook : NSObject 
{
	// book user settings
	BOOL					bookIsLoaded;
	BOOL					_settingsChanged;
	BOOL					_wasPlaying;
	
	NSMutableArray			*formatPlugins;
	id<TBPluginInterface>	currentPlugin;
	
	//TalkingBookType		_controlMode;
	levelControlMode		_levelNavConMode;
	levelControlMode		_maxLevelConMode;
	
	TBBookData				*bookData;

	BOOL					_hasPageNavigation;
	BOOL					_hasPhraseNavigation;
	BOOL					_hasSentenceNavigation;
	BOOL					_hasWordNavigation;
	
	// bindings
	BOOL					canPlay;
	
	// outlets
	IBOutlet NSPanel		*infoPanel;
	IBOutlet NSWindow		*textWindow;
	IBOutlet NSView			*infoView;
	IBOutlet NSView			*textView;

}


- (BOOL)openBookWithURL:(NSURL *)aURL;
- (void)play;
- (void)pause;

- (void)nextSegment;
- (void)previousSegment;
- (void)upOneLevel;
- (void)downOneLevel;
- (void)fastForwardAudio;
- (void)fastRewindAudio;

- (void)jumpToPoint:(NSString *)aNodePath andTime:(NSString *)aTimeStr;
- (NSString *)currentControlPositionID;
- (NSString *)currentTimePosition;



- (void)showHideBookInfo;
- (void)showHideTextWindow;
- (void)gotoPage;
- (NSDictionary *)getCurrentPageInfo;
- (void)setAudioPlayRate:(float)aRate;
- (void)setAudioVolume:(float)aVolumeLevel;
- (void)setAudioSkipDuration:(double)newDuration;

@property (readwrite,assign)		TBBookData  *bookData;
@property (readwrite)				BOOL		bookIsLoaded;

@property (readonly)				BOOL		canPlay;

@property (readonly, assign)		id<TBPluginInterface>	currentPlugin;

@end
