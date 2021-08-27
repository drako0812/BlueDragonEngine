export module bde.config;

import <cstdint>;
import <string>;
import <vector>;
import <map>;
import <any>;
import <variant>;
import <optional>;

namespace bde {

    export enum class ConfigValueType {
        Invalid,
        Int,
        Float,
        String,
        List,
        Map,
    };

    export using ConfigString = std::string;
    export using ConfigList = std::vector<std::any>;
    export using ConfigMap = std::map<ConfigString, std::any>;
    export using ConfigInt = std::int64_t;
    export using ConfigFloat = double;
    export using ConfigValue = std::variant<ConfigInt, ConfigFloat, ConfigString, ConfigList, ConfigMap>;

    template<class Type>
    export using ConfigOptional = std::optional<Type>;

    export using OString = ConfigOptional<ConfigString>;
    export using OList = ConfigOptional<ConfigList>;
    export using OMap = ConfigOptional<ConfigMap>;
    export using OInt = ConfigOptional<ConfigInt>;
    export using OFloat = ConfigOptional<ConfigFloat>;
    export using OValue = ConfigOptional<ConfigValue>;

    export class ConfigCategory {
    public:
        ConfigMap Items;
    };

    export class Configuration {
    public:
        std::map<ConfigString, ConfigCategory> Categories;

        OValue Get(ConfigString const & category, ConfigString const & key) const;
        OInt GetInt(ConfigString const & category, ConfigString const & key) const;
        OFloat GetFloat(ConfigString const & category, ConfigString const & key) const;
        OString GetString(ConfigString const & category, ConfigString const & key) const;
        OList GetList(ConfigString const & category, ConfigString const & key) const;
        OMap GetMap(ConfigString const & category, ConfigString const & key) const;

        bool DoesCategoryExit(ConfigString const & category);
        bool DoesValueExist(ConfigString const & category, ConfigString const & key) const;

        ConfigValueType GetValueType(ConfigString const & category, ConfigString const & key) const;

        Configuration & Clear();
        Configuration & RemoveCategory(ConfigString const & category);
        Configuration & Remove(ConfigString const & category, ConfigString const & key);
        Configuration & CreateCategory(ConfigString const & category);
        Configuration & Set(ConfigString const & category, ConfigString const & key, ConfigValue const & value);
        Configuration & SetInt(ConfigString const & category, ConfigString const & key, ConfigInt const & value);
        Configuration & SetFloat(ConfigString const & category, ConfigString const & key, ConfigFloat const & value);
        Configuration & SetString(ConfigString const & category, ConfigString const & key, ConfigString const & value);
        Configuration & SetList(ConfigString const & category, ConfigString const & key, ConfigList const & value);
        Configuration & SetMap(ConfigString const & category, ConfigString const & key, ConfigMap const & value);
    };

}
