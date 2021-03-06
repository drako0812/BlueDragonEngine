//module;
//#include "toml++/toml.h"
export module bde.config;
//
//import bde.errors;
//import <cstdint>;
//import <string>;
//import <vector>;
//import <map>;
//import <any>;
//import <variant>;
//import <optional>;
//import <format>;
//import <filesystem>;
//
//namespace bde {
//
//    export enum class ConfigValueType {
//        Invalid,
//        Int,
//        Float,
//        String,
//        List,
//        Map,
//        IntList,
//        FloatList,
//        StringList,
//    };
//
//    export using ConfigInt = std::int64_t;
//    export using ConfigFloat = double;
//    export using ConfigString = std::string;
//    export using ConfigList = std::vector<std::any>;
//    export using ConfigMap = std::map<ConfigString, std::any>;
//    export using ConfigIntList = std::vector<ConfigInt>;
//    export using ConfigFloatList = std::vector<ConfigFloat>;
//    export using ConfigStringList = std::vector<ConfigString>;
//    export using ConfigValue = std::variant<ConfigInt, ConfigFloat, ConfigString, ConfigList, ConfigMap, ConfigIntList, ConfigFloatList, ConfigStringList>;
//
//    export template<class Type> using ConfigOptional = std::optional<Type>;
//
//    export using OInt = ConfigOptional<ConfigInt>;
//    export using OFloat = ConfigOptional<ConfigFloat>;
//    export using OString = ConfigOptional<ConfigString>;
//    export using OList = ConfigOptional<ConfigList>;
//    export using OMap = ConfigOptional<ConfigMap>;
//    export using OIntList = ConfigOptional<ConfigIntList>;
//    export using OFloatList = ConfigOptional<ConfigFloatList>;
//    export using OStringList = ConfigOptional<ConfigStringList>;
//    export using OValue = ConfigOptional<ConfigValue>;
//
//    export class ConfigCategory {
//    public:
//        std::map<ConfigString, ConfigValue> Items;
//
//        OValue Get(ConfigString const & key) const;
//        OInt GetInt(ConfigString const & key) const;
//        OFloat GetFloat(ConfigString const & key) const;
//        OString GetString(ConfigString const & key) const;
//        OList GetList(ConfigString const & key) const;
//        OMap GetMap(ConfigString const & key) const;
//        OIntList GetIntList(ConfigString const & key) const;
//        OFloatList GetFloatList(ConfigString const & key) const;
//        OStringList GetStringList(ConfigString const & key) const;
//
//        bool DoesValueExist(ConfigString const & key) const;
//
//        ConfigValueType GetValueType(ConfigString const & key) const;
//
//        ConfigCategory & Clear();
//        ConfigCategory & Remove(ConfigString const & key);
//        ConfigCategory & Set(ConfigString const & key, ConfigValue const & value);
//        ConfigCategory & SetInt(ConfigString const & key, ConfigInt value);
//        ConfigCategory & SetFloat(ConfigString const & key, ConfigFloat value);
//        ConfigCategory & SetString(ConfigString const & key, ConfigString const & value);
//        ConfigCategory & SetList(ConfigString const & key, ConfigList const & value);
//        ConfigCategory & SetMap(ConfigString const & key, ConfigMap const & value);
//        ConfigCategory & SetIntList(ConfigString const & key, ConfigIntList const & value);
//        ConfigCategory & SetFloatList(ConfigString const & key, ConfigFloatList const & value);
//        ConfigCategory & SetStringList(ConfigString const & key, ConfigStringList const & value);
//    };
//
//    export class Configuration {
//    public:
//        std::map<ConfigString, ConfigCategory> Categories;
//
//        void LoadFromTOML(std::path const & file_path, bool ignore_missing_file = true);
//
//        OValue Get(ConfigString const & category, ConfigString const & key) const;
//        OInt GetInt(ConfigString const & category, ConfigString const & key) const;
//        OFloat GetFloat(ConfigString const & category, ConfigString const & key) const;
//        OString GetString(ConfigString const & category, ConfigString const & key) const;
//        OList GetList(ConfigString const & category, ConfigString const & key) const;
//        OMap GetMap(ConfigString const & category, ConfigString const & key) const;
//        OIntList GetIntList(ConfigString const & category, ConfigString const & key) const;
//        OFloatList GetFloatList(ConfigString const & category, ConfigString const & key) const;
//        OStringList GetStringList(ConfigString const & category, ConfigString const & key) const;
//
//        bool DoesCategoryExist(ConfigString const & category) const;
//        bool DoesValueExist(ConfigString const & category, ConfigString const & key) const;
//
//        ConfigValueType GetValueType(ConfigString const & category, ConfigString const & key) const;
//
//        Configuration & Clear();
//        Configuration & RemoveCategory(ConfigString const & category);
//        Configuration & Remove(ConfigString const & category, ConfigString const & key);
//        Configuration & CreateCategory(ConfigString const & category);
//        Configuration & Set(ConfigString const & category, ConfigString const & key, ConfigValue const & value);
//        Configuration & SetInt(ConfigString const & category, ConfigString const & key, ConfigInt value);
//        Configuration & SetFloat(ConfigString const & category, ConfigString const & key, ConfigFloat value);
//        Configuration & SetString(ConfigString const & category, ConfigString const & key, ConfigString const & value);
//        Configuration & SetList(ConfigString const & category, ConfigString const & key, ConfigList const & value);
//        Configuration & SetMap(ConfigString const & category, ConfigString const & key, ConfigMap const & value);
//        Configuration & SetIntList(ConfigString const & category, ConfigString const & key, ConfigIntList const & value);
//        Configuration & SetFloatList(ConfigString const & category, ConfigString const & key, ConfigFloatList const & value);
//        Configuration & SetStringList(ConfigString const & category, ConfigString const & key, ConfigStringList const & value);
//    };
//
//    export class ConfigurationFileMissingError : public BDEException {
//    public:
//        ConfigurationFileMissingError(std::string const & file_path);
//    };
//
//    void Configuration::LoadFromTOML(std::path const & file_path, bool ignore_missing_file) {
//        if (!std::exists(file_path)) {
//            if (!ignore_missing_files) {
//                throw ConfigurationFileMissingError(file_path.string());
//            }
//            return;
//        }
//
//        auto tbl = toml::parse_file(file_path.string());
//
//        // Loop through top-level keys (these will be our Categories)
//        for (auto const & cat : tbl) {
//            auto key = cat->first;
//            auto value = cat->second;
//
//            if (!DoesCategoryExist(key)) {
//                CreateCategory(key);
//            }
//
//            for (auto const & item : *(value.as_table())) {
//                auto key2 = item->first;
//                auto value2 = item->second;
//
//                // Figure out the type of value2
//                if (value2.is_table()) { // Map
//                    SetMap(key, key2, value2.as_table()); // TODO: This probably needs to be recursively converted
//                } else if (value2.is_array()) { // List
//                    if (value2.is_homogeneous(toml::node_type::string)) { // StringList
//                    } else if (value2.is_homogeneous(toml::node_type::floating_point)) { // FloatList
//                    } else if (value2.is_homogeneous(toml::node_type::integer)) { // IntList
//                    }
//
//                    // Basic List
//                } else if (value2.is_string()) { // String
//                } else if (value2.is_number()) { // Int or Float
//                    if (value2.is_integer()) { // Int
//                    } else { // Float
//                    }
//                }
//            }
//        }
//    }
//
//    OValue Configuration::Get(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).Get(key);
//    }
//
//    OInt Configuration::GetInt(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).GetInt(key);
//    }
//
//    OFloat Configuration::GetFloat(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).GetFloat(key);
//    }
//
//    OString Configuration::GetString(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).GetString(key);
//    }
//
//    OList Configuration::GetList(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).GetList(key);
//    }
//
//    OMap Configuration::GetMap(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).GetMap(key);
//    }
//
//    OIntList Configuration::GetIntList(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).GetIntList(key);
//    }
//
//    OFloatList Configuration::GetFloatList(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).GetFloatList(key);
//    }
//
//    OStringList Configuration::GetStringList(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesCategoryExist(category)) { return std::nullopt; }
//        return Categories.at(category).GetStringList(key);
//    }
//
//    bool Configuration::DoesCategoryExist(ConfigString const & category) const {
//        return Categories.contains(category);
//    }
//
//    bool Configuration::DoesValueExist(ConfigString const & category, ConfigString const & key) const {
//        if (!Categories.contains(category)) { return false; }
//        return Categories.at(category).DoesValueExist(key);
//    }
//
//    ConfigValueType Configuration::GetValueType(ConfigString const & category, ConfigString const & key) const {
//        if (!DoesValueExist(category, key)) { return ConfigValueType::Invalid; }
//
//        return Categories.at(category).GetValueType(key);
//    }
//
//    Configuration & Configuration::Clear() {
//        Categories.clear();
//        return *this;
//    }
//
//    Configuration & Configuration::RemoveCategory(ConfigString const & category) {
//        Categories.erase(category);
//        return *this;
//    }
//
//    Configuration & Configuration::Remove(ConfigString const & category, ConfigString const & key) {
//        if (DoesCategoryExist(category)) {
//            Categories.at(category).Remove(key);
//        }
//        return *this;
//    }
//
//    export class ConfigurationCategoryExistsError : public BDEException {
//    public:
//        ConfigurationCategoryExistsError(std::string const & category);
//    };
//
//    Configuration & Configuration::CreateCategory(ConfigString const & category) {
//        if (DoesCategoryExist(category)) {
//            throw ConfigurationCategoryExistsError(category);
//        }
//
//        Categories.insert({ category, ConfigCategory{} });
//        return *this;
//    }
//
//    export class ConfigurationCategoryMissingError : public BDEException {
//    public:
//        ConfigurationCategoryMissingError(std::string const & category);
//    };
//
//    Configuration & Configuration::Set(ConfigString const & category, ConfigString const & key, ConfigValue const & value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).Set(key, value);
//        return *this;
//    }
//
//    Configuration & Configuration::SetInt(ConfigString const & category, ConfigString const & key, ConfigInt value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).SetInt(key, value);
//        return *this;
//    }
//
//    Configuration & Configuration::SetFloat(ConfigString const & category, ConfigString const & key, ConfigFloat value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).SetFloat(key, value);
//        return *this;
//    }
//
//    Configuration & Configuration::SetString(ConfigString const & category, ConfigString const & key, ConfigString const & value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).SetString(key, value);
//        return *this;
//    }
//
//    Configuration & Configuration::SetList(ConfigString const & category, ConfigString const & key, ConfigList const & value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).SetList(key, value);
//        return *this;
//    }
//
//    Configuration & Configuration::SetMap(ConfigString const & category, ConfigString const & key, ConfigMap const & value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).SetMap(key, value);
//        return *this;
//    }
//
//    Configuration & Configuration::SetIntList(ConfigString const & category, ConfigString const & key, ConfigIntList const & value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).SetIntList(key, value);
//        return *this;
//    }
//
//    Configuration & Configuration::SetFloatList(ConfigString const & category, ConfigString const & key, ConfigFloatList const & value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).SetFloatList(key, value);
//        return *this;
//    }
//
//    Configuration & Configuration::SetStringList(ConfigString const & category, ConfigString const & key, ConfigStringList const & value) {
//        if (!DoesCategoryExist(category)) { throw ConfigurationCategoryMissingError(category); }
//        Categories.at(category).SetStringList(key, value);
//        return *this;
//    }
//
//    ConfigurationCategoryExistsError::ConfigurationCategoryExistsError(std::string const & category) : BDEException(std::format("ConfigurationCategoryExistsError: \"{}\"", category)) { }
//
//    ConfigurationCategoryMissingError::ConfigurationCategoryMissingError(std::string const & category) : BDEException(std::format("ConfigurationCategoryMissingError: \"{}\"", category)) { }
//
//    OValue ConfigCategory::Get(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        return Items.at(key);
//    }
//
//    OInt ConfigCategory::GetInt(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        if (GetValueType(key) != ConfigValueType::Int) { return std::nullopt; }
//        //return std::any_cast<ConfigInt>(Items.at(key));
//        return std::get<ConfigInt>(Items.at(key));
//    }
//
//    OFloat ConfigCategory::GetFloat(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        if (GetValueType(key) != ConfigValueType::Float) { return std::nullopt; }
//        //return std::any_cast<ConfigFloat>(Items.at(key));
//        return std::get<ConfigFloat>(Items.at(key));
//    }
//
//    OString ConfigCategory::GetString(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        if (GetValueType(key) != ConfigValueType::String) { return std::nullopt; }
//        //return std::any_cast<ConfigString>(Items.at(key));
//        return std::get<ConfigString>(Items.at(key));
//    }
//
//    OList ConfigCategory::GetList(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        if (GetValueType(key) != ConfigValueType::List) { return std::nullopt; }
//        //return std::any_cast<ConfigList>(Items.at(key));
//        return std::get<ConfigList>(Items.at(key));
//    }
//
//    OMap ConfigCategory::GetMap(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        if (GetValueType(key) != ConfigValueType::Map) { return std::nullopt; }
//        //return std::any_cast<ConfigMap>(Items.at(key));
//        return std::get<ConfigMap>(Items.at(key));
//    }
//
//    OIntList ConfigCategory::GetIntList(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        if (GetValueType(key) != ConfigValueType::IntList) { return std::nullopt; }
//        return std::get<ConfigIntList>(Items.at(key));
//    }
//
//    OFloatList ConfigCategory::GetFloatList(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        if (GetValueType(key) != ConfigValueType::FloatList) { return std::nullopt; }
//        return std::get<ConfigFloatList>(Items.at(key));
//    }
//
//    OStringList ConfigCategory::GetStringList(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return std::nullopt; }
//        if (GetValueType(key) != ConfigValueType::StringList) { return std::nullopt; }
//        return std::get<ConfigStringList>(Items.at(key));
//    }
//
//    bool ConfigCategory::DoesValueExist(ConfigString const & key) const {
//        return Items.contains(key);
//    }
//
//    ConfigValueType ConfigCategory::GetValueType(ConfigString const & key) const {
//        if (!DoesValueExist(key)) { return ConfigValueType::Invalid; }
//
//        auto v = Get(key).value();
//        if (std::holds_alternative<ConfigInt>(v)) {
//            return ConfigValueType::Int;
//        } else if (std::holds_alternative<ConfigFloat>(v)) {
//            return ConfigValueType::Float;
//        } else if (std::holds_alternative<ConfigString>(v)) {
//            return ConfigValueType::String;
//        } else if (std::holds_alternative<ConfigList>(v)) {
//            return ConfigValueType::List;
//        } else if (std::holds_alternative<ConfigMap>(v)) {
//            return ConfigValueType::Map;
//        } else if (std::holds_alternative<ConfigIntList>(v)) {
//            return ConfigValueType::IntList;
//        } else if (std::holds_alternative<ConfigFloatList>(v)) {
//            return ConfigValueType::FloatList;
//        } else if (std::holds_alternative<ConfigStringList>(v)) {
//            return ConfigValueType::StringList;
//        }
//
//        return ConfigValueType::Invalid;
//    }
//
//    ConfigCategory & ConfigCategory::Clear() {
//        Items.clear();
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::Remove(ConfigString const & key) {
//        if (DoesValueExist(key)) {
//            Items.erase(key);
//        }
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::Set(ConfigString const & key, ConfigValue const & value) {
//        Items.insert({ key, value });
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::SetInt(ConfigString const & key, ConfigInt value) {
//        Items.insert({ key, ConfigValue{value} });
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::SetFloat(ConfigString const & key, ConfigFloat value) {
//        Items.insert({ key, ConfigValue{value} });
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::SetString(ConfigString const & key, ConfigString const & value) {
//        Items.insert({ key, ConfigValue{value} });
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::SetList(ConfigString const & key, ConfigList const & value) {
//        Items.insert({ key, ConfigValue{value} });
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::SetMap(ConfigString const & key, ConfigMap const & value) {
//        Items.insert({ key, ConfigValue{value} });
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::SetIntList(ConfigString const & key, ConfigIntList const & value) {
//        Items.insert({ key, ConfigValue{value} });
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::SetFloatList(ConfigString const & key, ConfigFloatList const & value) {
//        Items.insert({ key, ConfigValue{value} });
//        return *this;
//    }
//
//    ConfigCategory & ConfigCategory::SetStringList(ConfigString const & key, ConfigStringList const & value) {
//        Items.insert({ key, ConfigValue{value} });
//        return *this;
//    }
//
//    ConfigurationFileMissingError::ConfigurationFileMissingError(std::string const & file_path) : BDEException(std::format("ConfigurationFileMissingError: \"{}\"", file_path)) { }
//
//}
