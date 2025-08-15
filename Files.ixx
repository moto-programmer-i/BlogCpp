// �t�@�C��������Utlis
export module Files;

import std;

// C++17����͕�����̈����͊�{string_view
// �Q�l https://yohhoy.hatenadiary.jp/entry/20171113/p1

namespace Files {
    /// <summary>
    /// C++�̓f�t�H���g�ł͗�O���łȂ����ߐݒ�
    /// </summary>
    /// <param name="file"></param>
    export void initForException(std::ifstream& file) {
        //�G���[�̂Ƃ��͗�O��throw����悤�ɐݒ�
        // https://dormolin.livedoor.blog/archives/50353376.html
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    }

    // 
    
    /// <summary>
    /// �t�@�C���̑S�Ă̍s��ǂݍ���
    /// </summary>
    /// <param name="filename">�t�@�C���p�X</param>
    /// <returns>�S�Ă̍s</returns>
    export std::vector<std::string> readAllLines(std::string_view filename) {
        std::vector<std::string> lines;
        std::ifstream file(filename.data());
        initForException(file);

        while (!file.eof()) {
            // vector�̖�����string�𒼐ڍ\�z
            // https://zenn.dev/mafafa/articles/370875167e4a3a
            lines.emplace_back();
            std::getline(file, lines.back());
        }

        return lines;
    }
}