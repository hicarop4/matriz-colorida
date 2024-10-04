from PIL import Image

# Carrega a imagem BMP
img = Image.open("imagem.jpg")

# Converte para escala de cinza
img = img.convert("L")

# Define um threshold para converter em preto e branco (0 ou 255)
threshold = 128
img = img.point(lambda p: 255 if p > threshold else 0)

# Obter as dimensões da imagem
width, height = img.size

# Abre o arquivo de saída em modo texto
with open("imagem_p3.ppm", "w") as f:
    # Escreve o cabeçalho P3
    f.write(f"P3\n{width} {height}\n255\n")
    
    # Escreve os pixels (0 ou 255)
    for y in range(height):
        for x in range(width):
            pixel = img.getpixel((x, y))
            f.write(f"{pixel} {pixel} {pixel} ")
        f.write("\n")