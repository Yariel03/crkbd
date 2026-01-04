# ⌨️ Teclado Corne - Configuración "Yariel"

Este repositorio contiene la configuración personalizada para el teclado **Corne (crkbd)**, optimizada para productividad, programación y control multimedia.

## 🚀 Características Principales
- **OLED Optimizado:** Pantalla secundaria con letrero marquesina que respeta el tiempo de apagado (`OLED_TIMEOUT`).
- **Combos Inteligentes:** Acceso rápido a retroceso, flechas de código y capas administrativas.
- **Home Row Mods:** Modificadores (GUI, ALT, CTRL, SFT) integrados en las teclas base para evitar fatiga.
- **5 Capas Especializadas:** Desde calculadora hasta control de mouse.

---

## ⚙️ Instalación y Uso

### 1. Requisitos Previos (Linux)
Necesitas tener instalado QMK y las herramientas de compilación.

**Arch Linux / Manjaro:**
```bash
sudo pacman -S qmk
```

**Ubuntu / Debian / Fedora:**
Es recomendable usar pip (Python):
```bash
python3 -m pip install --user qmk
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

**Configuración inicial de QMK:**
```bash
qmk setup
# Responde 'y' a las preguntas para instalar dependencias y clonar el repo oficial
```

### 2. Configurar este Keymap
Para usar esta configuración, debes colocar esta carpeta dentro del directorio de QMK.

```bash
# Asumiendo que estás en la raíz de este repositorio y qmk_firmware está en tu home
mkdir -p ~/qmk_firmware/keyboards/crkbd/keymaps/
ln -s $(pwd) ~/qmk_firmware/keyboards/crkbd/keymaps/Yariel
```

### 3. Compilar
Para generar el archivo `.hex` sin flashear:

```bash
qmk compile -kb crkbd -km Yariel
```

### 4. Flashear (Grabar en el teclado)
Conecta tu teclado por USB. Si es la primera vez o tienes problemas, asegúrate de conectar el lado **izquierdo** (Master).

```bash
qmk flash -kb crkbd -km Yariel
```
*Cuando veas `Waiting for USB serial port...`, presiona el botón **RESET** en el teclado (o haz puente en los pines GND y RST).*

> **Nota para Split:** Para actualizar ambos lados, desconecta el USB, conéctalo al lado derecho, ejecuta el comando de flash nuevamente y presiona Reset en ese lado.

---

## 🗺️ Distribución de Capas

> **Nota sobre índices:** Los números pequeños indican la posición física de la tecla (0-41) para referencia en programación.

### Capa 0: Base (QWERTY)
*La capa principal con modificadores en la fila central (Home Row Mods).*

| L-Lado | Q | W | E | R | T | | Y | U | I | O | P | BKSP |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0-5** | ESC | Q | W | E | R | T | | Y | U | I | O | P | BSPC |
| **6-11** | **TAB** | A/GUI | S/ALT | D/CTL | F/SFT | G | | H | J/SFT | K/CTL | L/ALT | ;/GUI | ' |
| **12-17** | **SFT** | Z | X | C | V | B | | N | M | , | . | / | L3/FN |
| **Thmb** | | | **36:GUI** | **37:L1**| **38:SPC** | | **39:ENT** | **40:L2**| **41:RALT** | | | |

### Capa 1: Calculadora & Números
*Activada con el pulgar izquierdo (`L1`).*

| L-Lado | . | . | . | . | . | | NUM | 7 | 8 | 9 | * | DEL |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0-5** | . | . | . | . | . | . | | NUM | 7 | 8 | 9 | * | DEL |
| **6-11** | **CAPS** | . | . | . | . | . | | . | 4 | 5 | 6 | + | - |
| **12-17** | . | . | . | . | . | . | | . | 1 | 2 | 3 | . | / |
| **Thmb** | | | . | . | **SPC** | | **ENT** | **L3** | **0** | | | |

### Capa 2: Símbolos & Navegación
*Activada con el pulgar derecho (`L2`).*

| L-Lado | ` | ! | @ | # | $ | % | | ^ | & | * | ( | ) | BKSP |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0-5** | ` / ~ | 1 | 2 | 3 | 4 | 5 | | 6 | 7 | 8 | 9 | 0 | BSPC |
| **6-11** | . | -/GUI | =/ALT | {/CTL | }/SFT | \ | | ← | ↓ | ↑ | → | HOME | END |
| **12-17** | . | _ | + | [ | ] | \ | | INS | PGUP | PGDN | . | . | . |
| **Thmb** | | | **GUI** | **L3** | **SPC** | | **ENT** | . | **RALT** | | | |

### Capa 3: Funciones & RGB
*Activada con `MO(3)` o combinaciones de pulgares.*

| L-Lado | F1 | F2 | F3 | F4 | F5 | F6 | | F7 | F8 | F9 | F10 | F11 | F12 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0-5** | F1 | F2 | F3 | F4 | F5 | F6 | | F7 | F8 | F9 | F10 | F11 | F12 |
| **6-11** | . | PLAY | PREV | NEXT | MUTE | VOL- | | VOL+ | RGB_TG | SAT+ | VAL+ | HUE+ | MOD+ |
| **12-17** | . | PSCR | . | . | . | . | | . | SAT- | VAL- | HUE- | MOD- | . |
| **Thmb** | | | **GUI** | . | **SPC** | | **ENT** | . | **RALT** | | | |

### Capa 4: Administración & Mouse
*Activada manteniendo **Espacio + Enter**.*

| L-Lado | RESET | Alt+F4 | UNDO | CUT | COPY | PSTE | | . | BTN1 | M_UP | BTN2 | . | . |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0-5** | **RESET** | Alt+F4 | UNDO | CUT | COPY | PSTE | | . | BTN1 | M_UP | BTN2 | . | . |
| **6-11** | . | . | . | Ctl+BS | . | . | | . | M_LFT | M_DWN | M_RGHT | . | . |
| **12-17** | . | . | . | . | . | . | | . | . | . | . | . | . |
| **Thmb** | | | **GUI** | . | **SPC** | | **ENT** | . | **RALT** | | | |

---

## ⚡ Combos de Teclado
| Teclas | Acción | Descripción |
| :--- | :--- | :--- |
| `SPC` + `ENT` | **MO(4)** | Acceso a capa administrativa y mouse |
| `.` + `/` | **=>{}** | Atajo para funciones flecha en JavaScript/TS |
| `H` + `J` | **BSPC** | Retroceso sin mover la mano de la posición base |

---

## 🛠️ Archivos en este Repo
- `keymap.c`: Lógica principal y definición de capas.
- `config.h`: Configuraciones de hardware, tiempos de espera y OLED.
- `rules.mk`: Módulos de QMK activados (OLED, RGB, Combos).
- `crkbd_rev1_Yariel.hex`: Firmware listo para flashear.
- `layout_viewer.html`: Visor visual para imprimir tu configuración.

---
*Configurado con orgullo por Yariel.*