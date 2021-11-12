L200: LD   I,  #000           ; A000
      LD   V0, #00            ; 6000
      LD   V1, #00            ; 6100
      LD   V2, #05            ; 6205
      LD   V3, #08            ; 6308
      LD   V4, #07            ; 6407
      LD   V5, #09            ; 6509
L20E: CLS                     ; 00E0
      DRW  V0, V1, %101         ; D015
      SKNP V2                 ; E2A1
      ADD  V1, #81            ; 7181
      SKNP V3                 ; E3A1
      ADD  V1, #01            ; 7101
      SKNP V4                 ; E4A1
      ADD  V0, #81            ; 7081
      SKNP V5                 ; E5A1
      ADD  V0, #01            ; 7001
      JP   L20E               ; 120E
