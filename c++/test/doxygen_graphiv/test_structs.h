/** 
 * @struct Innermost
 * 内层结构体，无嵌套
 */
struct Innermost {
    int data;  ///< 存储整数数据
};

/** 
 * @struct Middle
 * 中层结构体，包含 Innermost
 */
struct Middle {
    Innermost inner;  ///< 内层结构体实例
    float value;      ///< 浮点数成员
};

/** 
 * @struct Outer
 * 外层结构体，包含 Middle
 */
struct Outer {
    Middle middle;      ///< 中层结构体实例
    std::string name;   ///< 字符串成员
};

/** 
 * @struct DeeplyNested
 * 多层嵌套示例：Outer 包含 Middle，Middle 包含 Innermost
 */
struct DeeplyNested {
    Outer outer;  ///< 三层嵌套的结构体
    double depth; ///< 深度值
};