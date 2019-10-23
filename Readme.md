Yifan Wang  
yifanwang0916@outlook.com

## Homework for EE669 multi media compression in USC  
All function warpped for homework is named end with `_run`  
 
### Homework1
Shannon-Fano in `ShannonFano.hpp`:

    void SF_run(const char* name)
Huffman in `Huffman_GS.hpp`:

    void H_run(const string& name)
Adaptive Huffman in `Huffman_adp.hpp`:  

    void HA_run(char* name, char* opt)

    opt -> "-c" for conpression
        -> "-d" for decoding

### Homework2
BAC in `BAC.hpp`:

    void BAC_run(const char* name, unsigned int A, unsigned int C, int currentState, int MPS, const string& mapping)

    mapping -> "BP" for bit plane
            -> "SF" for Shannon-Fano
            -> "H" for Huffman

CABAC in `CABAC.hpp`:

    void CABAC_run(const char* name, int contextbits, const string mapping)

Improved CABAC using block mapping in  `CABAC.hpp`:

    void CABAC_A_run(const char* name, int contextbits, int block)

    block -> block size should be divided exactly by image height and width

### Homework3
SQ in `SQ.hpp`:

    double SQ_run(vector<string>& train, string& name, const char* save, int bit, int iter)

    train -> list name of training image
    name -> test image
    save -> name of output image
    bit -> quantization bits
    iter -> number of iteration, if large than actual needs would not affect

Blocking part in `VQ.hpp`:

    VQ_Block_run(vector<string>& train, int block)

    input image should be 256x256
    
Use following to conver quantized image to raw position
    
    void VQ_Deblock_run(string& name, string& save, int block)

Standarder VQ use code in sub-floder `stdvd`, use following to install:

    mkdir build
    cd build
    cmake ..
    make
    cd ..

Tree structured VQ in sub-floder `tsvq` which include two main function in `tsvq.c` and `tsvqe.c` (one for training, one for testing). Provided code is modied into one single head file due to some bugs from global variables used in original code.

### Homework4
DCT, Quantized DCT and Quantized Factor generator in `JPEG.hpp`:

    vector<vector<double>> DCT(const vector<vector<double>>& data)

    vector<vector<int>> QuantizedDCT(const vector<vector<double>>& data)

    data -> 8*8 image blocks

    vector<vector<double>> GenerateQ(int N)

    N -> quality factor

JPEG compression use provided code in `jpeg-6b`. Install it in `Linux` use:

    ./configure
    make

Run it use:

    ./cjpeg -quality "N" "input">".jpg"
    -> compress "input" using quality factor "N" and save it as ".jpg"

    ./djpeg ".jpg">".raw"
    -> change ".jpg" to raw data and save it to ".raw"

Deblocking use filtering:

    void Deblocking_A_run(string name, int H, int W, int K)

