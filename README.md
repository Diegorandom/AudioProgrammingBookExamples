# The Audio Programming Book — examples and exercises

My working files from *The Audio Programming Book* (Boulanger & Lazzarini, MIT Press). Plain C, one directory per exercise, each one a self-contained `main` you can compile and run on its own.

The book builds up the arithmetic of musical sound — MIDI note numbers, frequencies, equal temperament, pitch bend, string lengths — before touching any audio library. These are those first chapters, written by hand instead of copied.

## What's here

| Directory | What it works out |
|---|---|
| `freq2midi` | The nearest MIDI note for a given frequency — and why the conversion is a logarithm, not a division |
| `midi2freq` | MIDI note → frequency in Hz. Two versions: a fixed table (`midi2freq.c`) and one that reads notes from the keyboard (`midi2freqUserInput.c`) |
| `midinote2stringlength` | The vibrating string length needed to sound a given note — the physics behind a fretboard |
| `pitchBend` | How a 14-bit pitch-bend value maps to a frequency offset, and why the range is defined by the receiver, not the sender |
| `PointerArithmetic` | Transposing a sequence of notes by walking it with pointers instead of indexing |
| `structs` | A note as a `struct` — the first time the code stores pitch, duration and amplitude as one thing |
| `MusicAnalysisProgram` | Serial-music analysis over a twelve-tone row |
| `classes` | The same analyser rewritten in C++ (`SerialMusicAnalyzer.cpp`), as the bridge to the second half of the book |

## Build and run

Every `.c` file compiles on its own. No build system, no dependencies beyond `libm`:

```bash
clang -O2 -o freq2midi freq2midi/freq2midi.c -lm
./freq2midi
```

On Linux, `cc` instead of `clang`. `-lm` is only needed by the ones that use `pow()` and `sqrt()`.

**All eight `.c` files compile clean with `clang -O2` on macOS** (checked 2026-10-23). One of them — `midi2freq/midi2freqUserInput.c` — didn't, and it was a real bug rather than an old-compiler quirk: it included `<cctype>` and called `std::isdigit` in a file with a `.c` extension. It now uses `<ctype.h>` and `isdigit`, which is what the rest of the file is written in.

## A note on the committed binaries

`midi2freq/midi2freq`, `MusicAnalysisProgram/smAnalysis` and `classes/smAnalyzer2` are compiled binaries that came along with the first commit. They're kept because deleting them would rewrite what the repo looked like when I was working through the book — but they are **not** what the source produces today on this machine, so build from source.

## License

Following the book's own convention: the listings are for study. The code here is mine, and you're welcome to learn from it.
