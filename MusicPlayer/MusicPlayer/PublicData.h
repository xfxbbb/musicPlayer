// 公共数据类
#pragma once
#include <QString>
namespace PublicData{
	enum MUSICWGTE{  // 音乐界面切换枚举
		E_ALLMUSIC,
		E_FAVOURITEMUSIC
	};
	static QString _strMusicPath{};
	static QString _strMusicName{};
}


