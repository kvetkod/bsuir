#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    string inputFileName, outputFileName;
    int iterationCount;

    cout << "Введите название входного BMP файла: ";
    cin >> inputFileName;

    cout << "Введите название выходного BMP файла: ";
    cin >> outputFileName;

    cout << "Введите количество итераций применения медианного фильтра (целое число >= 1): ";
    cin >> iterationCount;

    if (iterationCount < 1)
    {
        cerr << "Количество итераций должно быть целым числом, большим или равным 1." << endl;
        return 1;
    }

    ifstream inputFile(inputFileName, ios::binary);
    if (!inputFile)
    {
        cerr << "Не удалось открыть входной файл." << endl;
        return 1;
    }

   
    uint8_t fileHeader[14];
    inputFile.read(reinterpret_cast<char *>(fileHeader), 14);

    
    if (fileHeader[0] != 'B' || fileHeader[1] != 'M')
    {
        cerr << "Входной файл не является BMP файлом." << endl;
        return 1;
    }

    
    uint8_t infoHeader[40];
    inputFile.read(reinterpret_cast<char *>(infoHeader), 40);

    
    int32_t width = *reinterpret_cast<int32_t *>(&infoHeader[4]);
    int32_t height = *reinterpret_cast<int32_t *>(&infoHeader[8]);

   
    uint16_t bitCount = *reinterpret_cast<uint16_t *>(&infoHeader[14]);
    if (bitCount != 24)
    {
        cerr << "Поддерживаются только 24-битные BMP файлы." << endl;
        return 1;
    }

    int rowSize = (width * 3 + 3) & (~3);

    
    vector<uint8_t> pixelData(rowSize * abs(height));
    inputFile.seekg(*reinterpret_cast<uint32_t *>(&fileHeader[10]), ios::beg);
    inputFile.read(reinterpret_cast<char *>(pixelData.data()), pixelData.size());

    inputFile.close();

    
    bool topDown = (height < 0);
    height = abs(height);

    
    vector<vector<vector<uint8_t>>> image(height, vector<vector<uint8_t>>(width, vector<uint8_t>(3)));
    for (int y = 0; y < height; ++y)
    {
        int rowIndex = topDown ? y : (height - 1 - y);
        for (int x = 0; x < width; ++x)
        {
            int pixelIndex = rowIndex * rowSize + x * 3;
            image[y][x][0] = pixelData[pixelIndex + 0]; // Blue
            image[y][x][1] = pixelData[pixelIndex + 1]; // Green
            image[y][x][2] = pixelData[pixelIndex + 2]; // Red
        }
    }

    int kernelSize = 3;
    int edge = kernelSize / 2;

    vector<vector<vector<uint8_t>>> filteredImage = image;

    for (int iter = 0; iter < iterationCount; ++iter)
    {
        vector<vector<vector<uint8_t>>> currentImage = filteredImage;

        for (int y = edge; y < height - edge; ++y)
        {
            for (int x = edge; x < width - edge; ++x)
            {
                vector<uint8_t> reds, greens, blues;

                
                for (int ky = -edge; ky <= edge; ++ky)
                {
                    for (int kx = -edge; kx <= edge; ++kx)
                    {
                        blues.push_back(currentImage[y + ky][x + kx][0]);
                        greens.push_back(currentImage[y + ky][x + kx][1]);
                        reds.push_back(currentImage[y + ky][x + kx][2]);
                    }
                }

                
                sort(blues.begin(), blues.end());
                sort(greens.begin(), greens.end());
                sort(reds.begin(), reds.end());

                filteredImage[y][x][0] = blues[blues.size() / 2];
                filteredImage[y][x][1] = greens[greens.size() / 2];
                filteredImage[y][x][2] = reds[reds.size() / 2];
            }
        }
    }

    
    vector<uint8_t> outputPixelData(pixelData.size(), 0);
    for (int y = 0; y < height; ++y)
    {
        int rowIndex = topDown ? y : (height - 1 - y);
        for (int x = 0; x < width; ++x)
        {
            int pixelIndex = rowIndex * rowSize + x * 3;
            outputPixelData[pixelIndex + 0] = filteredImage[y][x][0]; // Blue
            outputPixelData[pixelIndex + 1] = filteredImage[y][x][1]; // Green
            outputPixelData[pixelIndex + 2] = filteredImage[y][x][2]; // Red
        }
    }

    
    ofstream outputFile(outputFileName, std::ios::binary);
    if (!outputFile)
    {
        cerr << "Не удалось открыть выходной файл." << endl;
        return 1;
    }

    
    outputFile.write(reinterpret_cast<char *>(fileHeader), 14);
    outputFile.write(reinterpret_cast<char *>(infoHeader), 40);

    
    outputFile.write(reinterpret_cast<char *>(outputPixelData.data()), outputPixelData.size());

    outputFile.close();

    cout << "Фильтрация завершена. Результат сохранён в " << outputFileName << endl;

    return 0;
}
