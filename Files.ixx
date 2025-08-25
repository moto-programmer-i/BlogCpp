// ファイル処理のUtlis
export module Files;

import std;

// C++17からは文字列の引数は基本string_view
// 参考 https://yohhoy.hatenadiary.jp/entry/20171113/p1

namespace Files {
    /// <summary>
    /// C++はデフォルトでは例外がでないため設定
    /// </summary>
    /// <param name="file"></param>
    export void initForException(std::ifstream& file) {
        //エラーのときは例外をthrowするように設定
        // https://dormolin.livedoor.blog/archives/50353376.html
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    }


    
    /// <summary>
    /// ファイルの全ての行を読み込む
    /// </summary>
    /// <param name="filename">ファイルパス</param>
    /// <returns>全ての行</returns>
    export std::vector<std::string> readAllLines(std::string_view filename) {
        std::vector<std::string> lines;
        std::ifstream file(filename.data());
        initForException(file);

        while (!file.eof()) {
            // vectorの末尾にstringを直接構築
            // https://zenn.dev/mafafa/articles/370875167e4a3a
            std::getline(file, lines.emplace_back());
        }

        return lines;
    }
}