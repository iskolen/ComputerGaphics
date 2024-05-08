#include "pch.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void errorCallback(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}

int main() {
    // Инициализация GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwSetErrorCallback(errorCallback);

    // Создание окна
    GLFWwindow* window = glfwCreateWindow(800, 600, "Texture Test", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Загрузка изображения
    int width, height, cnt;
    unsigned char* data = stbi_load("bricks.jpg", &width, &height, &cnt, 0);
    if (!data) {
        std::cerr << "Failed to load texture" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Установка настроек текстуры
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Освобождение памяти, занятой изображением
    stbi_image_free(data);

    // Основной цикл отрисовки
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Рисование прямоугольника с текстурой
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex2f(0.5f, -0.5f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2f(0.5f, 0.5f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2f(-0.5f, 0.5f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Очистка ресурсов
    glDeleteTextures(1, &textureID);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
