L200: LD   I,  #2FC           ; A2FC
      LD   VD, #00            ; 6D00
L204: LD   VE, #00            ; 6E00
L206: DRW  VD, VE, #3         ; DDE3
      ADD  VE, #06            ; 7E06
      SE   VE, #18            ; 3E18
      JP   L206               ; 1206
      ADD  VD, #06            ; 7D06
      SE   VD, #3C            ; 3D3C
      JP   L204               ; 1204
      LD   I,  #3F4           ; A3F4
      CALL L300               ; 2300
      CALL L300               ; 2300
      CALL L300               ; 2300
      CALL L300               ; 2300
      LD   VD, #00            ; 6D00
      LD   VE, #00            ; 6E00
      LD   VC, #00            ; 6C00
L224: LD   I,  #3F4           ; A3F4
      LD   V3, [I]            ; F365
      LD   [I], V3            ; F355
      LD   VB, #00            ; 6B00
L22C: LD   V0, K              ; F00A
      SE   V0, #0F            ; 300F
      JP   L24A               ; 124A
L232: SNE  VB, #00            ; 4B00
      JP   L22C               ; 122C
      ADD  VE, #FA            ; 7EFA
      LD   I,  #3FC           ; A3FC
      ADD  VB, #FF            ; 7BFF
      ADD  I,  VB             ; FB1E
      LD   V0, [I]            ; F065
      LD   F,  V0             ; F029
      DRW  VD, VE, #5         ; DDE5
      LD   I,  #2FC           ; A2FC
      DRW  VD, VE, #3         ; DDE3
      JP   L232               ; 1232
L24A: LD   VA, #F9            ; 6AF9
      ADD  VA, V0             ; 8A04
      SE   VF, #00            ; 3F00
      JP   L22C               ; 122C
      SNE  V0, #00            ; 4000
      JP   L22C               ; 122C
      LD   I,  #2FC           ; A2FC
      DRW  VD, VE, #3         ; DDE3
      LD   I,  #3FC           ; A3FC
      ADD  I,  VB             ; FB1E
      LD   [I], V0            ; F055
      LD   F,  V0             ; F029
      DRW  VD, VE, #5         ; DDE5
      ADD  VE, #06            ; 7E06
      ADD  VB, #01            ; 7B01
      SE   VB, #04            ; 3B04
      JP   L22C               ; 122C
      LD   V4, #00            ; 6400
      LD   V8, #00            ; 6800
      LD   VB, #00            ; 6B00
L272: LD   I,  #3FC           ; A3FC
      ADD  I,  VB             ; FB1E
      LD   V0, [I]            ; F065
      LD   V2, V0             ; 8200
      LD   I,  #3F8           ; A3F8
      ADD  I,  VB             ; FB1E
      LD   V0, [I]            ; F065
      LD   V3, V0             ; 8300
      CALL L30E               ; 230E
      LD   I,  #3FC           ; A3FC
      ADD  I,  VB             ; FB1E
      LD   V0, V2             ; 8020
      LD   [I], V0            ; F055
      LD   I,  #3F8           ; A3F8
      ADD  I,  VB             ; FB1E
      LD   V0, V3             ; 8030
      LD   [I], V0            ; F055
      ADD  VB, #01            ; 7B01
      SE   VB, #04            ; 3B04
      JP   L272               ; 1272
      SE   V8, #04            ; 3804
      JP   L2C2               ; 12C2
L29E: LD   VE, #00            ; 6E00
      LD   VD, #3C            ; 6D3C
      LD   V9, #00            ; 6900
L2A4: LD   I,  #3F4           ; A3F4
      ADD  I,  V9             ; F91E
      LD   V0, [I]            ; F065
      LD   F,  V0             ; F029
      DRW  VD, VE, #5         ; DDE5
      ADD  VE, #06            ; 7E06
      ADD  V9, #01            ; 7901
      SE   V9, #04            ; 3904
      JP   L2A4               ; 12A4
      LD   V0, #20            ; 6020
      LD   DT, V0             ; F015
L2BA: LD   V0, DT             ; F007
      SE   V0, #00            ; 3000
      JP   L2BA               ; 12BA
      JP   L29E               ; 129E
L2C2: LD   V4, #01            ; 6401
      LD   VA, #00            ; 6A00
L2C6: LD   VB, #00            ; 6B00
      LD   I,  #3FC           ; A3FC
      ADD  I,  VA             ; FA1E
      LD   V0, [I]            ; F065
      LD   V2, V0             ; 8200
L2D0: LD   I,  #3F8           ; A3F8
      ADD  I,  VB             ; FB1E
      LD   V0, [I]            ; F065
      LD   V3, V0             ; 8300
      CALL L30E               ; 230E
      LD   I,  #3F8           ; A3F8
      ADD  I,  VB             ; FB1E
      LD   V0, V3             ; 8030
      LD   [I], V0            ; F055
      ADD  VB, #01            ; 7B01
      SE   VB, #04            ; 3B04
      JP   L2D0               ; 12D0
      ADD  VA, #01            ; 7A01
      SE   VA, #04            ; 3A04
      JP   L2C6               ; 12C6
      ADD  VD, #06            ; 7D06
      LD   VE, #00            ; 6E00
      ADD  VC, #01            ; 7C01
      SE   VC, #0A            ; 3C0A
      JP   L224               ; 1224
      JP   L29E               ; 129E
L2FA: db #90, #F0, #00, #00
L2FE: db #60, #00
L300: RND  V0, #07            ; C007
      SNE  V0, #00            ; 4000
      JP   L300               ; 1300
      SNE  V0, #07            ; 4007
      JP   L300               ; 1300
      LD   [I], V0            ; F055
      RET                     ; 00EE
L30E: SE   V2, V3             ; 5230
      RET                     ; 00EE
      LD   I,  #2FA           ; A2FA
      SE   V4, #00            ; 3400
      LD   I,  #2FB           ; A2FB
      DRW  VD, VE, #1         ; DDE1
      ADD  VE, #02            ; 7E02
      ADD  V8, #01            ; 7801
      LD   V2, #0E            ; 620E
      LD   V3, #0F            ; 630F
      RET                     ; 00EE
