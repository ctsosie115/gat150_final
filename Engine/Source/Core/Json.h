#pragma once
#include "..//..//rapidjson/rapidjson-master/include/rapidjson/document.h"
#include "..//Renderer/Color.h"
#include "..//Renderer/Vector2.h"

#include <vector>
#include <Math/Rect.h>
#include <string>

#define READ_DATA(value, data)				Json::Read(value, #data, data)
#define READ_DATA_REQUIRED(value, data)		Json::Read(value, #data, data, false)
#define READ_DATA_NAME_REQUIRED(value, name, data)	JSON::Read(value, name, data)
#define READ_DATA_NAME(value, name, data)	JSON::Read(value, name, data, false)
#define HAS_DATA(value, data)				value.HasMember(#data)
#define GET_DATA(value, data)				value[#data]
//#define READ_DATA_STRUCT(value, gravityScale, rigidBodyDef);

namespace Json
{
	bool Load(const std::string& filename, rapidjson::Document& document);

	bool Read(const rapidjson::Value& value, const std::string& name, int& data, bool isRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, float& data, bool isRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, bool& data, bool isRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, std::string& data, bool isRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, Vector2& data, bool isRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, Color& data, bool isRequired = false);
	
	bool Read(const rapidjson::Value& value, const std::string& name, Rect& data, bool isRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, std::vector<int>& data, bool isRequired = false);
	bool Read(const rapidjson::Value& value, const std::string& name, std::vector<std::string>& data, bool isRequired = false);

	//template<typename T>
	//bool Read_Data_Struct(const rapidjson::Value& value, const T& data);

}

using json_t = rapidjson::Value;

