
#include "Data/DataManager.h"

DataManager::DataManager() {
	//Initialize the database
	/*pdb = NULL;
	std::string path = CCFileUtils::sharedFileUtils()->getWritablePath() + "save.db3";

	#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		path = CCFileUtils::sharedFileUtils()->getWritablePath();
		path += "/save.db3";

		FILE* file = fopen(dbPath.c_str(), "r");
		if (file == nullptr)
		{
			unsigned long size;
			const char* data = (char*)CCFileUtils::sharedFileUtils()->getFileData("dict.db", "rb", &size);
			file = fopen(dbPath.c_str(), "wb");
			fwrite(data, size, 1, file);
			CC_SAFE_DELETE_ARRAY(data);
		}
		fclose(file);

	#endif

	int result;
	result = sqlite3_open(path.c_str(), &pdb);
	if (result != SQLITE_OK) {
		CCLOG("open database failed,  number%d", result);
	}
	else {
		CCLOG("Open Database Succesful");
	}*/
}