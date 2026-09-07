# ⌨️ Teclado Corne - Configuración "Yariel"

Este repositorio contiene la configuración personalizada para el teclado **Corne (crkbd rev1)**, optimizada para desarrollo de software en **Arch Linux**, **Hyprland (Tiling WM)**, **Neovim** y **Tmux**.

## 🚀 Características Principales
- **Suite Simétrica de Delimitadores en Combos:** Paréntesis `()`, llaves `{}` y corchetes `[]` accesibles directamente en las 3 filas interiores de la Capa 0 sin cambiar de capa ni pulsar Shift.
- **Optimizado para Hyprland (Workspaces con Pulgares):** Cambio ágil entre los workspaces `1..0` mediante `MO(2)` (pulgar derecho) + `Super` (pulgar izquierdo) + número en fila superior.
- **Navegación Vim en Capa 2:** Flechas `LEFT, DOWN, UP, RIGHT` posicionadas sobre `H, J, K, L` en la mano derecha.
- **Home Row Mods (GACS):** Modificadores en la fila de descanso en Capa 0 y en Capa 2 (para mover ventanas en Hyprland y seleccionar texto con flechas Vim).
- **OLED Animado y Útil:** Pantalla maestra muestra estado de capa y bloqueos; pantalla esclava muestra animación marquesina (`@yariel_dev`).

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

### Capa 2: Símbolos, Hyprland & Navegación Vim
*Activada con el pulgar derecho (`MO(2)`).*
- **Fila superior (1..0):** Workspaces de Hyprland (`MO(2)` derecho + `Super` izquierdo + número).
- **Mano izquierda:** Home Row Mods (`GUI`, `ALT`, `CTL`, `SFT`). Interceptados en `process_record_user` para enviar `{` y `}` al pulsar rápido, y `Ctrl`/`Shift` al sostener.
- **Mano derecha:** Flechas Vim (`H, J, K, L` $\rightarrow$ `←, ↓, ↑, →`). Mueve ventanas en Hyprland o selecciona texto en Neovim con `Shift + flechas`.

| L-Lado | ` | ! | @ | # | $ | % | | ^ | & | * | ( | ) | BKSP |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0-5** | ` / ~ | 1 | 2 | 3 | 4 | 5 | | 6 | 7 | 8 | 9 | 0 | BSPC |
| **6-11** | . | -/GUI | =/ALT | {/CTL | }/SFT | \| | | ← | ↓ | ↑ | → | HOME | END |
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

## ⚡ Combos de Teclado (Capa 0)
Todos los combos se activan pulsando ambas teclas al mismo tiempo:

| Teclas | Salida / Acción | Descripción / Caso de Uso |
| :--- | :---: | :--- |
| `R` + `T` | **`(`** | Paréntesis de apertura |
| `Y` + `U` | **`)`** | Paréntesis de cierre |
| `F` + `G` | **`{`** | Llave de apertura |
| `H` + `J` | **`}`** | Llave de cierre |
| `V` + `B` | **`[`** | Corchete de apertura |
| `N` + `M` | **`]`** | Corchete de cierre |
| `.` + `/` | **`=>{}`** | Atajo para funciones flecha en JavaScript/TS |
| `SPC` + `ENT` | **`MO(4)`** | Capa 4 (Admin, accesos de sistema y mouse) |

---

## 🛠️ Archivos en este Repo
- `keymap.c`: Lógica principal y definición de capas.
- `config.h`: Configuraciones de hardware, tiempos de espera y OLED.
- `rules.mk`: Módulos de QMK activados (OLED, RGB, Combos).
- `crkbd_rev1_Yariel.hex`: Firmware listo para flashear.
- `layout_viewer.html`: Visor visual para imprimir tu configuración.

---
*Configurado con orgullo por Yariel.*