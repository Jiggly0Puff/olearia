//
//  TBNCCDocument.h
//  StdDaisyFormats
//
//  Created by Kieren Eaton on 11/09/08.
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

#import "TBControlDoc.h"

@interface TBNCCDocument : TBControlDoc
{
	BOOL loadFromCurrentLevel;
	
@private	
	NSUInteger			_currentNodeIndex;
	NSUInteger			_totalBodyNodes;
	NSXMLElement		*nccRootElement;
	
	NSArray				*_bodyNodes;
}

@property (readwrite) BOOL loadFromCurrentLevel;

@end
