// 公共数据类
#pragma once
#include <QString>
namespace PublicData{
	enum MUSICWGTE{  // 音乐界面切换枚举
		E_ALLMUSIC,
		E_FAVOURITEMUSIC
	};
	
	struct SongInfo{  
		// 歌曲信息
		QString _SongPath;
		QString _SongName;
	};
	

}


