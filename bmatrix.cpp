#include <cstring>
#include <system_error>
#include <vector>
namespace bmatrix{
		class bmatrix{
				public:
				std::vector<std::vector<int>> matrix;
				int length = 0;
				int height = 0;
				int padding = 0;

				bmatrix(int size){
						this->length = size / 8;
						if (length % 8){
								length++;
								padding = 8 - (length % 8);
						}
						this->height = size;

						matrix.resize(height);

						for (int i = 0 ; i < height ; i++)
								matrix[i].resize(height);
						
				}
				void validate_and_throw_if_invalid_pos(int i, int j) {
					if (i > height || j > height || i < 0 || j < 0) {
						throw std::invalid_argument(
							"Tried to access invalid position, matrix size: " + std::to_string(this->height)
									+ " requested position: " + std::to_string(i) + ", " + std::to_string(j));
					}
				}

				void set(int i, int j){
						validate_and_throw_if_invalid_pos(i, j);

						int j_index = j / 8;
						int j_bit = j % 8;
						matrix[i][j_index] |= (1 << j_bit);


				}

				int get(int i, int j){
						validate_and_throw_if_invalid_pos(i, j);

						int j_index = j / 8;
						int j_bit = j % 8;

						//return matrix[i][j_index] && (1 << j_bit);
						return (matrix[i][j_index] & (1 << j_bit)) != 0;

				}
		};

};
