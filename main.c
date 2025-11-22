// cl.exe main.c
// .\main.exe

// 用 GDI 截屏并计算屏幕平均亮度（Win11 + MSVC）
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> // HDC, HBITMAP, BITMAPINFO, GetDC, CreateCompatibleDC, CreateCompatibleBitmap, SelectObject, BitBlt, GetDIBits, DeleteObject, DeleteDC, ReleaseDC, GetSystemMetrics, SM_CXSCREEN, SM_CYSCREEN
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma comment(lib, "gdi32.lib") //GetDC, CreateCompatibleDC, CreateCompatibleBitmap, SelectObject, BitBlt, GetDIBits, DeleteObject, DeleteDC
#pragma comment(lib, "user32.lib") //ReleaseDC, GetSystemMetrics

// 截当前屏幕一次，并计算平均亮度（0.0 ~ 1.0）
double compute_screen_luminance(void) {
    HDC hScreenDC = GetDC(NULL); // 获取整个屏幕的 DC（NULL 表示整个屏幕）（Device Context）
    if(!hScreenDC) {
        fprintf(stderr, "GetDC failed.\n");
        goto cleanup;
    }

    HDC hMemDC = CreateCompatibleDC(hScreenDC); // 创建一个与屏幕 DC 兼容的内存 DC
    if(!hMemDC) {
        fprintf(stderr, "CreateCompatibleDC failed.\n");
        goto cleanup;
    }

    int width  = GetSystemMetrics(SM_CXSCREEN); // 屏幕宽度 SM_CXSCREEN是屏幕宽度
    int height = GetSystemMetrics(SM_CYSCREEN); // 屏幕高度 SM_CYSCREEN是屏幕高度
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height); // 创建一个与屏幕 DC 兼容的位图
    if(!hBitmap) {
        fprintf(stderr, "CreateCompatibleBitmap failed.\n");
        goto cleanup;
    }

    HGDIOBJ oldObj = SelectObject(hMemDC, hBitmap); // 绑定位图到内存 DC
    if(!oldObj) {
        fprintf(stderr, "SelectObject failed.\n");
        goto cleanup;
    }

    // 把屏幕画面拷贝到 hBitmap 里
    if(!BitBlt(hMemDC, 0, 0, width, height, hScreenDC, 0, 0, SRCCOPY)) { //SRCCOPY表示直接复制源矩形到目标矩形
        fprintf(stderr, "BitBlt failed.\n");
        SelectObject(hMemDC, oldObj);
        goto cleanup;
    }

    SelectObject(hMemDC, oldObj); // 解绑位图，防止后续删除时出错

    // 准备一个 32bpp 的 DIB 信息结构
    BITMAPINFO bmi; // 位图信息结构
    ZeroMemory(&bmi, sizeof(bmi)); // 清零
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER); // 结构体大小
    bmi.bmiHeader.biWidth       = width; // 宽度，left小是因为我们要从左到右扫描
    bmi.bmiHeader.biHeight      = -height;    // 负数 = top-down， top小是因为我们要从上到下扫描
    bmi.bmiHeader.biPlanes      = 1; // 必须为1
    bmi.bmiHeader.biBitCount    = 32;         // 32 bits BGRA
    bmi.bmiHeader.biCompression = BI_RGB; // 不压缩

    uint8_t* pixels = (uint8_t*)malloc(4 * width * height); // 每个像素4字节（BGRA）
    if(!pixels) {
        fprintf(stderr, "malloc failed.\n");
        goto cleanup;
    }

    // 从位图中获取像素数据
    if(!GetDIBits(hScreenDC, hBitmap, 0, height, pixels, &bmi, DIB_RGB_COLORS)) {
        fprintf(stderr, "GetDIBits failed.\n");
        goto cleanup;
    }

    const int stepX = 8; // 采样步长，减小计算量
    const int stepY = 8; // 采样步长，减小计算量
    double sum_luma = 0.0; // 亮度总和
    long count = 0; // 采样点数量
    for(int y = 0; y < height; y += stepY) {
        uint8_t* row = pixels + y * 4 * width; // 指向第 y 行的起始位置
        for(int x = 0; x < width; x += stepX) {
            uint8_t* px = row + x * 4;
            uint8_t B = px[0];
            uint8_t G = px[1];
            uint8_t R = px[2];
            double Y = 0.299 * R + 0.587 * G + 0.114 * B; // 计算亮度 Y
            sum_luma += Y;
            count++;
        }
    }

    double avg_luma = 0.0;
    if(count > 0) {
        avg_luma = sum_luma / (count * 255.0);
    } else {
        avg_luma = 0.0;
    }

cleanup:
    if(pixels) {
        free(pixels);
    }
    if(hBitmap) {
        DeleteObject(hBitmap);
    }
    if(hMemDC) {
        DeleteDC(hMemDC);
    }
    if (hScreenDC) {
        ReleaseDC(NULL, hScreenDC);
    }

    return avg_luma;
}

int main(void) {
    printf("GDI screen luminance demo (Ctrl+C 退出)\n");

    while(1) {
        double L = compute_screen_luminance();
        printf("Average screen luminance: %.3f\n", L);
        fflush(stdout);
        Sleep(500);  // 500ms 采样一次
    }
    return 0;
}
