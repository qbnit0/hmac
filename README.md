# C implementation of the HMAC algorithm
A minimal [HMAC](https://en.wikipedia.org/wiki/HMAC) (RFC 2104) implementation in C.

- No heap allocations (suitable for embedded use)
- Currently supports SHA-1 (Using [Steve Reid's SHA-1 implementation](https://github.com/clibs/sha1))
- Consists of a command-line utility (`hmac`) and C library (`lib2104`).
