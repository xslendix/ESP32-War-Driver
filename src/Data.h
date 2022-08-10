#pragma once

uint8_t const Dialog_plain_8[] PROGMEM = {
    0x08, // Width: 8
    0x0A, // Height: 10
    0x20, // First Char: 32
    0xE0, // Numbers of Chars: 224

    // Jump Table:
    0xFF, 0xFF, 0x00, 0x03, // 32:65535
    0x00, 0x00, 0x03, 0x03, // 33:0
    0x00, 0x03, 0x07, 0x04, // 34:3
    0x00, 0x0A, 0x0B, 0x07, // 35:10
    0x00, 0x15, 0x09, 0x05, // 36:21
    0x00, 0x1E, 0x0F, 0x08, // 37:30
    0x00, 0x2D, 0x0B, 0x06, // 38:45
    0x00, 0x38, 0x03, 0x02, // 39:56
    0x00, 0x3B, 0x05, 0x03, // 40:59
    0x00, 0x40, 0x05, 0x03, // 41:64
    0x00, 0x45, 0x07, 0x04, // 42:69
    0x00, 0x4C, 0x0B, 0x07, // 43:76
    0x00, 0x57, 0x04, 0x03, // 44:87
    0x00, 0x5B, 0x05, 0x03, // 45:91
    0x00, 0x60, 0x03, 0x03, // 46:96
    0x00, 0x63, 0x05, 0x03, // 47:99
    0x00, 0x68, 0x09, 0x05, // 48:104
    0x00, 0x71, 0x07, 0x05, // 49:113
    0x00, 0x78, 0x09, 0x05, // 50:120
    0x00, 0x81, 0x09, 0x05, // 51:129
    0x00, 0x8A, 0x09, 0x05, // 52:138
    0x00, 0x93, 0x09, 0x05, // 53:147
    0x00, 0x9C, 0x09, 0x05, // 54:156
    0x00, 0xA5, 0x09, 0x05, // 55:165
    0x00, 0xAE, 0x09, 0x05, // 56:174
    0x00, 0xB7, 0x09, 0x05, // 57:183
    0x00, 0xC0, 0x03, 0x03, // 58:192
    0x00, 0xC3, 0x04, 0x03, // 59:195
    0x00, 0xC7, 0x0B, 0x07, // 60:199
    0x00, 0xD2, 0x0B, 0x07, // 61:210
    0x00, 0xDD, 0x0B, 0x07, // 62:221
    0x00, 0xE8, 0x07, 0x04, // 63:232
    0x00, 0xEF, 0x0F, 0x08, // 64:239
    0x00, 0xFE, 0x09, 0x05, // 65:254
    0x01, 0x07, 0x09, 0x05, // 66:263
    0x01, 0x10, 0x0B, 0x06, // 67:272
    0x01, 0x1B, 0x0B, 0x06, // 68:283
    0x01, 0x26, 0x09, 0x05, // 69:294
    0x01, 0x2F, 0x07, 0x05, // 70:303
    0x01, 0x36, 0x0B, 0x06, // 71:310
    0x01, 0x41, 0x09, 0x06, // 72:321
    0x01, 0x4A, 0x03, 0x02, // 73:330
    0x01, 0x4D, 0x04, 0x02, // 74:333
    0x01, 0x51, 0x09, 0x05, // 75:337
    0x01, 0x5A, 0x07, 0x04, // 76:346
    0x01, 0x61, 0x0B, 0x07, // 77:353
    0x01, 0x6C, 0x09, 0x06, // 78:364
    0x01, 0x75, 0x0B, 0x06, // 79:373
    0x01, 0x80, 0x09, 0x05, // 80:384
    0x01, 0x89, 0x0B, 0x06, // 81:393
    0x01, 0x94, 0x0B, 0x06, // 82:404
    0x01, 0x9F, 0x09, 0x05, // 83:415
    0x01, 0xA8, 0x09, 0x05, // 84:424
    0x01, 0xB1, 0x09, 0x06, // 85:433
    0x01, 0xBA, 0x09, 0x05, // 86:442
    0x01, 0xC3, 0x0D, 0x08, // 87:451
    0x01, 0xD0, 0x09, 0x05, // 88:464
    0x01, 0xD9, 0x09, 0x05, // 89:473
    0x01, 0xE2, 0x09, 0x05, // 90:482
    0x01, 0xEB, 0x06, 0x03, // 91:491
    0x01, 0xF1, 0x06, 0x03, // 92:497
    0x01, 0xF7, 0x06, 0x03, // 93:503
    0x01, 0xFD, 0x09, 0x07, // 94:509
    0x02, 0x06, 0x08, 0x04, // 95:518
    0x02, 0x0E, 0x03, 0x04, // 96:526
    0x02, 0x11, 0x09, 0x05, // 97:529
    0x02, 0x1A, 0x09, 0x05, // 98:538
    0x02, 0x23, 0x07, 0x04, // 99:547
    0x02, 0x2A, 0x09, 0x05, // 100:554
    0x02, 0x33, 0x09, 0x05, // 101:563
    0x02, 0x3C, 0x05, 0x03, // 102:572
    0x02, 0x41, 0x0A, 0x05, // 103:577
    0x02, 0x4B, 0x09, 0x05, // 104:587
    0x02, 0x54, 0x03, 0x02, // 105:596
    0x02, 0x57, 0x04, 0x02, // 106:599
    0x02, 0x5B, 0x07, 0x05, // 107:603
    0x02, 0x62, 0x03, 0x02, // 108:610
    0x02, 0x65, 0x0F, 0x08, // 109:613
    0x02, 0x74, 0x09, 0x05, // 110:628
    0x02, 0x7D, 0x09, 0x05, // 111:637
    0x02, 0x86, 0x09, 0x05, // 112:646
    0x02, 0x8F, 0x0A, 0x05, // 113:655
    0x02, 0x99, 0x05, 0x03, // 114:665
    0x02, 0x9E, 0x07, 0x04, // 115:670
    0x02, 0xA5, 0x05, 0x03, // 116:677
    0x02, 0xAA, 0x09, 0x05, // 117:682
    0x02, 0xB3, 0x07, 0x05, // 118:691
    0x02, 0xBA, 0x0B, 0x07, // 119:698
    0x02, 0xC5, 0x07, 0x05, // 120:709
    0x02, 0xCC, 0x09, 0x05, // 121:716
    0x02, 0xD5, 0x07, 0x04, // 122:725
    0x02, 0xDC, 0x08, 0x05, // 123:732
    0x02, 0xE4, 0x04, 0x03, // 124:740
    0x02, 0xE8, 0x07, 0x05, // 125:744
    0x02, 0xEF, 0x0B, 0x07, // 126:751
    0x02, 0xFA, 0x08, 0x05, // 127:762
    0x03, 0x02, 0x08, 0x05, // 128:770
    0x03, 0x0A, 0x08, 0x05, // 129:778
    0x03, 0x12, 0x08, 0x05, // 130:786
    0x03, 0x1A, 0x08, 0x05, // 131:794
    0x03, 0x22, 0x08, 0x05, // 132:802
    0x03, 0x2A, 0x08, 0x05, // 133:810
    0x03, 0x32, 0x08, 0x05, // 134:818
    0x03, 0x3A, 0x08, 0x05, // 135:826
    0x03, 0x42, 0x08, 0x05, // 136:834
    0x03, 0x4A, 0x08, 0x05, // 137:842
    0x03, 0x52, 0x08, 0x05, // 138:850
    0x03, 0x5A, 0x08, 0x05, // 139:858
    0x03, 0x62, 0x08, 0x05, // 140:866
    0x03, 0x6A, 0x08, 0x05, // 141:874
    0x03, 0x72, 0x08, 0x05, // 142:882
    0x03, 0x7A, 0x08, 0x05, // 143:890
    0x03, 0x82, 0x08, 0x05, // 144:898
    0x03, 0x8A, 0x08, 0x05, // 145:906
    0x03, 0x92, 0x08, 0x05, // 146:914
    0x03, 0x9A, 0x08, 0x05, // 147:922
    0x03, 0xA2, 0x08, 0x05, // 148:930
    0x03, 0xAA, 0x08, 0x05, // 149:938
    0x03, 0xB2, 0x08, 0x05, // 150:946
    0x03, 0xBA, 0x08, 0x05, // 151:954
    0x03, 0xC2, 0x08, 0x05, // 152:962
    0x03, 0xCA, 0x08, 0x05, // 153:970
    0x03, 0xD2, 0x08, 0x05, // 154:978
    0x03, 0xDA, 0x08, 0x05, // 155:986
    0x03, 0xE2, 0x08, 0x05, // 156:994
    0x03, 0xEA, 0x08, 0x05, // 157:1002
    0x03, 0xF2, 0x08, 0x05, // 158:1010
    0x03, 0xFA, 0x08, 0x05, // 159:1018
    0xFF, 0xFF, 0x00, 0x03, // 160:65535
    0x04, 0x02, 0x04, 0x03, // 161:1026
    0x04, 0x06, 0x07, 0x05, // 162:1030
    0x04, 0x0D, 0x07, 0x05, // 163:1037
    0x04, 0x14, 0x09, 0x05, // 164:1044
    0x04, 0x1D, 0x09, 0x05, // 165:1053
    0x04, 0x26, 0x04, 0x03, // 166:1062
    0x04, 0x2A, 0x08, 0x04, // 167:1066
    0x04, 0x32, 0x07, 0x04, // 168:1074
    0x04, 0x39, 0x0D, 0x08, // 169:1081
    0x04, 0x46, 0x07, 0x04, // 170:1094
    0x04, 0x4D, 0x09, 0x05, // 171:1101
    0x04, 0x56, 0x0B, 0x07, // 172:1110
    0x04, 0x61, 0x05, 0x03, // 173:1121
    0x04, 0x66, 0x0D, 0x08, // 174:1126
    0x04, 0x73, 0x05, 0x04, // 175:1139
    0x04, 0x78, 0x05, 0x04, // 176:1144
    0x04, 0x7D, 0x0B, 0x07, // 177:1149
    0x04, 0x88, 0x05, 0x03, // 178:1160
    0x04, 0x8D, 0x05, 0x03, // 179:1165
    0x04, 0x92, 0x03, 0x04, // 180:1170
    0x04, 0x95, 0x09, 0x05, // 181:1173
    0x04, 0x9E, 0x0A, 0x05, // 182:1182
    0x04, 0xA8, 0x03, 0x03, // 183:1192
    0x04, 0xAB, 0x06, 0x04, // 184:1195
    0x04, 0xB1, 0x05, 0x03, // 185:1201
    0x04, 0xB6, 0x07, 0x04, // 186:1206
    0x04, 0xBD, 0x09, 0x05, // 187:1213
    0x04, 0xC6, 0x0F, 0x08, // 188:1222
    0x04, 0xD5, 0x0F, 0x08, // 189:1237
    0x04, 0xE4, 0x0F, 0x08, // 190:1252
    0x04, 0xF3, 0x08, 0x04, // 191:1267
    0x04, 0xFB, 0x09, 0x05, // 192:1275
    0x05, 0x04, 0x09, 0x05, // 193:1284
    0x05, 0x0D, 0x09, 0x05, // 194:1293
    0x05, 0x16, 0x09, 0x05, // 195:1302
    0x05, 0x1F, 0x09, 0x05, // 196:1311
    0x05, 0x28, 0x09, 0x05, // 197:1320
    0x05, 0x31, 0x0D, 0x08, // 198:1329
    0x05, 0x3E, 0x0B, 0x06, // 199:1342
    0x05, 0x49, 0x09, 0x05, // 200:1353
    0x05, 0x52, 0x09, 0x05, // 201:1362
    0x05, 0x5B, 0x09, 0x05, // 202:1371
    0x05, 0x64, 0x09, 0x05, // 203:1380
    0x05, 0x6D, 0x03, 0x02, // 204:1389
    0x05, 0x70, 0x03, 0x02, // 205:1392
    0x05, 0x73, 0x03, 0x02, // 206:1395
    0x05, 0x76, 0x03, 0x02, // 207:1398
    0x05, 0x79, 0x0B, 0x06, // 208:1401
    0x05, 0x84, 0x09, 0x06, // 209:1412
    0x05, 0x8D, 0x0B, 0x06, // 210:1421
    0x05, 0x98, 0x0B, 0x06, // 211:1432
    0x05, 0xA3, 0x0B, 0x06, // 212:1443
    0x05, 0xAE, 0x0B, 0x06, // 213:1454
    0x05, 0xB9, 0x0B, 0x06, // 214:1465
    0x05, 0xC4, 0x0B, 0x07, // 215:1476
    0x05, 0xCF, 0x0B, 0x06, // 216:1487
    0x05, 0xDA, 0x09, 0x06, // 217:1498
    0x05, 0xE3, 0x09, 0x06, // 218:1507
    0x05, 0xEC, 0x09, 0x06, // 219:1516
    0x05, 0xF5, 0x09, 0x06, // 220:1525
    0x05, 0xFE, 0x09, 0x05, // 221:1534
    0x06, 0x07, 0x09, 0x05, // 222:1543
    0x06, 0x10, 0x09, 0x05, // 223:1552
    0x06, 0x19, 0x09, 0x05, // 224:1561
    0x06, 0x22, 0x09, 0x05, // 225:1570
    0x06, 0x2B, 0x09, 0x05, // 226:1579
    0x06, 0x34, 0x09, 0x05, // 227:1588
    0x06, 0x3D, 0x09, 0x05, // 228:1597
    0x06, 0x46, 0x09, 0x05, // 229:1606
    0x06, 0x4F, 0x0F, 0x08, // 230:1615
    0x06, 0x5E, 0x08, 0x04, // 231:1630
    0x06, 0x66, 0x09, 0x05, // 232:1638
    0x06, 0x6F, 0x09, 0x05, // 233:1647
    0x06, 0x78, 0x09, 0x05, // 234:1656
    0x06, 0x81, 0x09, 0x05, // 235:1665
    0x06, 0x8A, 0x03, 0x02, // 236:1674
    0x06, 0x8D, 0x03, 0x02, // 237:1677
    0x06, 0x90, 0x03, 0x02, // 238:1680
    0x06, 0x93, 0x03, 0x02, // 239:1683
    0x06, 0x96, 0x09, 0x05, // 240:1686
    0x06, 0x9F, 0x09, 0x05, // 241:1695
    0x06, 0xA8, 0x09, 0x05, // 242:1704
    0x06, 0xB1, 0x09, 0x05, // 243:1713
    0x06, 0xBA, 0x09, 0x05, // 244:1722
    0x06, 0xC3, 0x09, 0x05, // 245:1731
    0x06, 0xCC, 0x09, 0x05, // 246:1740
    0x06, 0xD5, 0x0B, 0x07, // 247:1749
    0x06, 0xE0, 0x09, 0x05, // 248:1760
    0x06, 0xE9, 0x09, 0x05, // 249:1769
    0x06, 0xF2, 0x09, 0x05, // 250:1778
    0x06, 0xFB, 0x09, 0x05, // 251:1787
    0x07, 0x04, 0x09, 0x05, // 252:1796
    0x07, 0x0D, 0x09, 0x05, // 253:1805
    0x07, 0x16, 0x09, 0x05, // 254:1814
    0x07, 0x1F, 0x09, 0x05, // 255:1823

    // Font Data:
    0x00, 0x00, 0xBC,                                                 // 33
    0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x0C,                         // 34
    0x00, 0x00, 0xA8, 0x00, 0x7C, 0x00, 0xEA, 0x00, 0x3E, 0x00, 0x28, // 35
    0x00, 0x00, 0x98, 0x00, 0xA8, 0x00, 0xFC, 0x01, 0xA8,             // 36
    0x00, 0x00, 0x1C, 0x00, 0x14, 0x00, 0xDC, 0x00, 0x30, 0x00, 0xEC, 0x00,
    0xA0, 0x00, 0xE0,                                                 // 37
    0x00, 0x00, 0x60, 0x00, 0xBC, 0x00, 0xF4, 0x00, 0xC4, 0x00, 0xA0, // 38
    0x00, 0x00, 0x0C,                                                 // 39
    0x00, 0x00, 0x7C, 0x00, 0x82,                                     // 40
    0x00, 0x00, 0x82, 0x00, 0x7C,                                     // 41
    0x24, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x18,                         // 42
    0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0xF8, 0x00, 0x20, 0x00, 0x20, // 43
    0x00, 0x00, 0x80, 0x01,                                           // 44
    0x00, 0x00, 0x20, 0x00, 0x20,                                     // 45
    0x00, 0x00, 0x80,                                                 // 46
    0x80, 0x01, 0x70, 0x00, 0x0C,                                     // 47
    0x00, 0x00, 0x78, 0x00, 0x84, 0x00, 0x84, 0x00, 0x78,             // 48
    0x00, 0x00, 0x84, 0x00, 0xFC, 0x00, 0x80,                         // 49
    0x00, 0x00, 0x84, 0x00, 0xC4, 0x00, 0xA4, 0x00, 0x98,             // 50
    0x00, 0x00, 0x84, 0x00, 0xA4, 0x00, 0xA4, 0x00, 0xD8,             // 51
    0x00, 0x00, 0x60, 0x00, 0x58, 0x00, 0xFC, 0x00, 0x40,             // 52
    0x00, 0x00, 0x9C, 0x00, 0x94, 0x00, 0x94, 0x00, 0x64,             // 53
    0x00, 0x00, 0x78, 0x00, 0xAC, 0x00, 0xA4, 0x00, 0xE4,             // 54
    0x00, 0x00, 0x04, 0x00, 0x84, 0x00, 0x74, 0x00, 0x0C,             // 55
    0x00, 0x00, 0xD8, 0x00, 0xA4, 0x00, 0xA4, 0x00, 0xD8,             // 56
    0x00, 0x00, 0x9C, 0x00, 0x94, 0x00, 0xD4, 0x00, 0x78,             // 57
    0x00, 0x00, 0x90,                                                 // 58
    0x00, 0x00, 0x90, 0x01,                                           // 59
    0x00, 0x00, 0x20, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x48, // 60
    0x00, 0x00, 0x50, 0x00, 0x50, 0x00, 0x50, 0x00, 0x50, 0x00, 0x50, // 61
    0x00, 0x00, 0x48, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x20, // 62
    0x00, 0x00, 0x04, 0x00, 0xB4, 0x00, 0x0C,                         // 63
    0x00, 0x00, 0x70, 0x00, 0x88, 0x00, 0x74, 0x01, 0x54, 0x01, 0x74, 0x01,
    0x4C, 0x00, 0x38,                                                 // 64
    0x80, 0x00, 0x70, 0x00, 0x4C, 0x00, 0x70, 0x00, 0x80,             // 65
    0x00, 0x00, 0xFC, 0x00, 0xA4, 0x00, 0xA4, 0x00, 0xDC,             // 66
    0x00, 0x00, 0x78, 0x00, 0xCC, 0x00, 0x84, 0x00, 0x84, 0x00, 0x88, // 67
    0x00, 0x00, 0xFC, 0x00, 0x84, 0x00, 0x84, 0x00, 0x84, 0x00, 0x78, // 68
    0x00, 0x00, 0xFC, 0x00, 0xA4, 0x00, 0xA4, 0x00, 0xA4,             // 69
    0x00, 0x00, 0xFC, 0x00, 0x24, 0x00, 0x24,                         // 70
    0x00, 0x00, 0x78, 0x00, 0x8C, 0x00, 0x84, 0x00, 0x94, 0x00, 0x78, // 71
    0x00, 0x00, 0xFC, 0x00, 0x20, 0x00, 0x20, 0x00, 0xFC,             // 72
    0x00, 0x00, 0xFC,                                                 // 73
    0x00, 0x02, 0xFC, 0x03,                                           // 74
    0x00, 0x00, 0xFC, 0x00, 0x30, 0x00, 0x68, 0x00, 0xC4,             // 75
    0x00, 0x00, 0xFC, 0x00, 0x80, 0x00, 0x80,                         // 76
    0x00, 0x00, 0xFC, 0x00, 0x1C, 0x00, 0x70, 0x00, 0x1C, 0x00, 0xFC, // 77
    0x00, 0x00, 0xFC, 0x00, 0x18, 0x00, 0x60, 0x00, 0xFC,             // 78
    0x00, 0x00, 0x78, 0x00, 0x84, 0x00, 0x84, 0x00, 0x84, 0x00, 0x78, // 79
    0x00, 0x00, 0xFC, 0x00, 0x14, 0x00, 0x14, 0x00, 0x1C,             // 80
    0x00, 0x00, 0x78, 0x00, 0x84, 0x00, 0x84, 0x00, 0x84, 0x01, 0x78, // 81
    0x00, 0x00, 0xFC, 0x00, 0x14, 0x00, 0x34, 0x00, 0x6C, 0x00, 0x80, // 82
    0x00, 0x00, 0x98, 0x00, 0x94, 0x00, 0xB4, 0x00, 0xE4,             // 83
    0x04, 0x00, 0x04, 0x00, 0xFC, 0x00, 0x04, 0x00, 0x04,             // 84
    0x00, 0x00, 0x7C, 0x00, 0x80, 0x00, 0x80, 0x00, 0x7C,             // 85
    0x04, 0x00, 0x38, 0x00, 0xC0, 0x00, 0x38, 0x00, 0x04,             // 86
    0x0C, 0x00, 0xF0, 0x00, 0x78, 0x00, 0x04, 0x00, 0x78, 0x00, 0xF0, 0x00,
    0x0C,                                                       // 87
    0x84, 0x00, 0x4C, 0x00, 0x30, 0x00, 0x4C, 0x00, 0x84,       // 88
    0x04, 0x00, 0x0C, 0x00, 0xF0, 0x00, 0x0C, 0x00, 0x04,       // 89
    0x00, 0x00, 0x84, 0x00, 0xE4, 0x00, 0xB4, 0x00, 0x8C,       // 90
    0x00, 0x00, 0xFC, 0x01, 0x04, 0x01,                         // 91
    0x0C, 0x00, 0x70, 0x00, 0x80, 0x01,                         // 92
    0x00, 0x00, 0x04, 0x01, 0xFC, 0x01,                         // 93
    0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x04, 0x00, 0x08,       // 94
    0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02,             // 95
    0x00, 0x00, 0x04,                                           // 96
    0x00, 0x00, 0xE0, 0x00, 0xB0, 0x00, 0xB0, 0x00, 0xF0,       // 97
    0x00, 0x00, 0xFE, 0x00, 0x90, 0x00, 0x90, 0x00, 0x60,       // 98
    0x00, 0x00, 0x60, 0x00, 0x90, 0x00, 0x90,                   // 99
    0x00, 0x00, 0x60, 0x00, 0x90, 0x00, 0x90, 0x00, 0xFE,       // 100
    0x00, 0x00, 0x60, 0x00, 0xB0, 0x00, 0xB0, 0x00, 0xB0,       // 101
    0x10, 0x00, 0xFE, 0x00, 0x12,                               // 102
    0x00, 0x00, 0x60, 0x00, 0x90, 0x02, 0x90, 0x02, 0xF0, 0x01, // 103
    0x00, 0x00, 0xFE, 0x00, 0x10, 0x00, 0x10, 0x00, 0xF0,       // 104
    0x00, 0x00, 0xF4,                                           // 105
    0x00, 0x02, 0xF4, 0x03,                                     // 106
    0x00, 0x00, 0xFE, 0x00, 0x60, 0x00, 0x90,                   // 107
    0x00, 0x00, 0xFE,                                           // 108
    0x00, 0x00, 0xF0, 0x00, 0x10, 0x00, 0x10, 0x00, 0xF0, 0x00, 0x10, 0x00,
    0x10, 0x00, 0xF0,                                                 // 109
    0x00, 0x00, 0xF0, 0x00, 0x10, 0x00, 0x10, 0x00, 0xF0,             // 110
    0x00, 0x00, 0x60, 0x00, 0x90, 0x00, 0x90, 0x00, 0x60,             // 111
    0x00, 0x00, 0xF0, 0x03, 0x90, 0x00, 0x90, 0x00, 0x60,             // 112
    0x00, 0x00, 0x60, 0x00, 0x90, 0x00, 0x90, 0x00, 0xF0, 0x03,       // 113
    0x00, 0x00, 0xF0, 0x00, 0x10,                                     // 114
    0x00, 0x00, 0xB0, 0x00, 0xB0, 0x00, 0xD0,                         // 115
    0x10, 0x00, 0xF8, 0x00, 0x90,                                     // 116
    0x00, 0x00, 0xF0, 0x00, 0x80, 0x00, 0x80, 0x00, 0xF0,             // 117
    0x10, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0x10,                         // 118
    0x30, 0x00, 0xC0, 0x00, 0x30, 0x00, 0x30, 0x00, 0xC0, 0x00, 0x30, // 119
    0x90, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x90,                         // 120
    0x00, 0x00, 0x10, 0x02, 0xE0, 0x03, 0x60, 0x00, 0x10,             // 121
    0x00, 0x00, 0x90, 0x00, 0xD0, 0x00, 0xF0,                         // 122
    0x00, 0x00, 0x20, 0x00, 0xDC, 0x01, 0x04, 0x01,                   // 123
    0x00, 0x00, 0xFC, 0x03,                                           // 124
    0x00, 0x00, 0x04, 0x01, 0xDC, 0x01, 0x20,                         // 125
    0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x60, 0x00, 0x40, 0x00, 0x40, // 126
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 127
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 128
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 129
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 130
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 131
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 132
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 133
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 134
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 135
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 136
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 137
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 138
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 139
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 140
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 141
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 142
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 143
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 144
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 145
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 146
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 147
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 148
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 149
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 150
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 151
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 152
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 153
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 154
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 155
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 156
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 157
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 158
    0xFC, 0x01, 0x04, 0x01, 0x04, 0x01, 0xFC, 0x01,                   // 159
    0x00, 0x00, 0xD0, 0x03,                                           // 161
    0x00, 0x00, 0xF0, 0x00, 0xF8, 0x01, 0x90,                         // 162
    0xA0, 0x00, 0xFC, 0x00, 0xA4, 0x00, 0xA4,                         // 163
    0x88, 0x00, 0x70, 0x00, 0x50, 0x00, 0x70, 0x00, 0x88,             // 164
    0x54, 0x00, 0x58, 0x00, 0xE0, 0x00, 0x58, 0x00, 0x54,             // 165
    0x00, 0x00, 0xDC, 0x01,                                           // 166
    0x00, 0x00, 0x3C, 0x01, 0x54, 0x01, 0xE4, 0x01,                   // 167
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,                         // 168
    0x00, 0x00, 0x78, 0x00, 0xCC, 0x00, 0xB4, 0x00, 0xB4, 0x00, 0xCC, 0x00,
    0x78,                                                             // 169
    0x00, 0x00, 0x58, 0x00, 0x5C, 0x00, 0x5C,                         // 170
    0x00, 0x00, 0x60, 0x00, 0xF0, 0x00, 0x60, 0x00, 0xF0,             // 171
    0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x60, // 172
    0x00, 0x00, 0x20, 0x00, 0x20,                                     // 173
    0x00, 0x00, 0x78, 0x00, 0xCC, 0x00, 0xB4, 0x00, 0xB4, 0x00, 0xCC, 0x00,
    0x78,                                                             // 174
    0x00, 0x00, 0x04, 0x00, 0x04,                                     // 175
    0x00, 0x00, 0x0C, 0x00, 0x0C,                                     // 176
    0x00, 0x00, 0x90, 0x00, 0x90, 0x00, 0xFC, 0x00, 0x90, 0x00, 0x90, // 177
    0x00, 0x00, 0x14, 0x00, 0x1C,                                     // 178
    0x00, 0x00, 0x1C, 0x00, 0x14,                                     // 179
    0x00, 0x00, 0x04,                                                 // 180
    0x00, 0x00, 0xF0, 0x03, 0x80, 0x00, 0x80, 0x00, 0xF0,             // 181
    0x00, 0x00, 0x3C, 0x00, 0xFC, 0x01, 0x04, 0x00, 0xFC, 0x01,       // 182
    0x00, 0x00, 0x20,                                                 // 183
    0x00, 0x00, 0x00, 0x02, 0x00, 0x03,                               // 184
    0x00, 0x00, 0x14, 0x00, 0x1C,                                     // 185
    0x00, 0x00, 0x5C, 0x00, 0x54, 0x00, 0x5C,                         // 186
    0x00, 0x00, 0xF0, 0x00, 0x60, 0x00, 0xF0, 0x00, 0x60,             // 187
    0x00, 0x00, 0x14, 0x00, 0x9C, 0x00, 0x70, 0x00, 0x18, 0x00, 0x04, 0x00,
    0xC0, 0x00, 0xE0, // 188
    0x00, 0x00, 0x14, 0x00, 0x9C, 0x00, 0x70, 0x00, 0x18, 0x00, 0x04, 0x00,
    0xA0, 0x00, 0xE0, // 189
    0x00, 0x00, 0x1C, 0x00, 0x94, 0x00, 0x60, 0x00, 0x18, 0x00, 0x04, 0x00,
    0xC0, 0x00, 0xE0,                                     // 190
    0x00, 0x00, 0x00, 0x03, 0xD0, 0x02, 0x00, 0x02,       // 191
    0x80, 0x00, 0x70, 0x00, 0x4E, 0x00, 0x72, 0x00, 0x80, // 192
    0x80, 0x00, 0x70, 0x00, 0x4E, 0x00, 0x72, 0x00, 0x80, // 193
    0x80, 0x00, 0x70, 0x00, 0x4C, 0x00, 0x70, 0x00, 0x80, // 194
    0x80, 0x00, 0x72, 0x00, 0x4E, 0x00, 0x72, 0x00, 0x80, // 195
    0x80, 0x00, 0x72, 0x00, 0x4C, 0x00, 0x72, 0x00, 0x80, // 196
    0x80, 0x00, 0x60, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x80, // 197
    0x80, 0x00, 0x70, 0x00, 0x4C, 0x00, 0xFC, 0x00, 0xA4, 0x00, 0xA4, 0x00,
    0xA4,                                                             // 198
    0x00, 0x00, 0x78, 0x00, 0xCC, 0x02, 0x84, 0x03, 0x84, 0x00, 0x88, // 199
    0x00, 0x00, 0xFC, 0x00, 0xA6, 0x00, 0xA6, 0x00, 0xA4,             // 200
    0x00, 0x00, 0xFC, 0x00, 0xA6, 0x00, 0xA6, 0x00, 0xA4,             // 201
    0x00, 0x00, 0xFC, 0x00, 0xA6, 0x00, 0xA6, 0x00, 0xA4,             // 202
    0x00, 0x00, 0xFC, 0x00, 0xA6, 0x00, 0xA4, 0x00, 0xA6,             // 203
    0x02, 0x00, 0xFE,                                                 // 204
    0x02, 0x00, 0xFE,                                                 // 205
    0x02, 0x00, 0xFE,                                                 // 206
    0x02, 0x00, 0xFC,                                                 // 207
    0x20, 0x00, 0xFC, 0x00, 0xA4, 0x00, 0x84, 0x00, 0xCC, 0x00, 0x78, // 208
    0x00, 0x00, 0xFC, 0x00, 0x1A, 0x00, 0x62, 0x00, 0xFC,             // 209
    0x00, 0x00, 0x78, 0x00, 0x86, 0x00, 0x86, 0x00, 0x84, 0x00, 0x78, // 210
    0x00, 0x00, 0x78, 0x00, 0x86, 0x00, 0x86, 0x00, 0x84, 0x00, 0x78, // 211
    0x00, 0x00, 0x78, 0x00, 0x84, 0x00, 0x84, 0x00, 0x84, 0x00, 0x78, // 212
    0x00, 0x00, 0x78, 0x00, 0x86, 0x00, 0x86, 0x00, 0x86, 0x00, 0x78, // 213
    0x00, 0x00, 0x78, 0x00, 0x86, 0x00, 0x84, 0x00, 0x86, 0x00, 0x78, // 214
    0x00, 0x00, 0x88, 0x00, 0x50, 0x00, 0x20, 0x00, 0x50, 0x00, 0x88, // 215
    0x00, 0x00, 0xB8, 0x00, 0xE4, 0x00, 0x94, 0x00, 0x8C, 0x00, 0x74, // 216
    0x00, 0x00, 0x7C, 0x00, 0x82, 0x00, 0x82, 0x00, 0x7C,             // 217
    0x00, 0x00, 0x7C, 0x00, 0x82, 0x00, 0x82, 0x00, 0x7C,             // 218
    0x00, 0x00, 0x7C, 0x00, 0x82, 0x00, 0x82, 0x00, 0x7C,             // 219
    0x00, 0x00, 0x7E, 0x00, 0x80, 0x00, 0x80, 0x00, 0x7E,             // 220
    0x04, 0x00, 0x0E, 0x00, 0xF2, 0x00, 0x0C, 0x00, 0x04,             // 221
    0x00, 0x00, 0xFC, 0x00, 0x28, 0x00, 0x28, 0x00, 0x38,             // 222
    0x00, 0x00, 0xFC, 0x00, 0x02, 0x00, 0x9A, 0x00, 0xE4,             // 223
    0x00, 0x00, 0xE4, 0x00, 0xB0, 0x00, 0xB0, 0x00, 0xF0,             // 224
    0x00, 0x00, 0xE4, 0x00, 0xB0, 0x00, 0xB0, 0x00, 0xF0,             // 225
    0x00, 0x00, 0xE0, 0x00, 0xB4, 0x00, 0xB4, 0x00, 0xF0,             // 226
    0x00, 0x00, 0xE0, 0x00, 0xBC, 0x00, 0xBC, 0x00, 0xF0,             // 227
    0x00, 0x00, 0xE0, 0x00, 0xB4, 0x00, 0xB4, 0x00, 0xF0,             // 228
    0x00, 0x00, 0xE0, 0x00, 0xB6, 0x00, 0xB6, 0x00, 0xF0,             // 229
    0x00, 0x00, 0xE0, 0x00, 0xB0, 0x00, 0xB0, 0x00, 0x60, 0x00, 0xB0, 0x00,
    0xB0, 0x00, 0xB0,                                                 // 230
    0x00, 0x00, 0x60, 0x00, 0x90, 0x02, 0x90, 0x03,                   // 231
    0x00, 0x00, 0x60, 0x00, 0xB4, 0x00, 0xB0, 0x00, 0xB0,             // 232
    0x00, 0x00, 0x60, 0x00, 0xB4, 0x00, 0xB0, 0x00, 0xB0,             // 233
    0x00, 0x00, 0x60, 0x00, 0xB4, 0x00, 0xB4, 0x00, 0xB0,             // 234
    0x00, 0x00, 0x60, 0x00, 0xB4, 0x00, 0xB0, 0x00, 0xB4,             // 235
    0x04, 0x00, 0xF0,                                                 // 236
    0x04, 0x00, 0xF0,                                                 // 237
    0x04, 0x00, 0xF4,                                                 // 238
    0x04, 0x00, 0xF0,                                                 // 239
    0x00, 0x00, 0x60, 0x00, 0x94, 0x00, 0x9C, 0x00, 0x70,             // 240
    0x00, 0x00, 0xFC, 0x00, 0x1C, 0x00, 0x1C, 0x00, 0xF0,             // 241
    0x00, 0x00, 0x64, 0x00, 0x90, 0x00, 0x90, 0x00, 0x60,             // 242
    0x00, 0x00, 0x64, 0x00, 0x90, 0x00, 0x90, 0x00, 0x60,             // 243
    0x00, 0x00, 0x60, 0x00, 0x94, 0x00, 0x94, 0x00, 0x60,             // 244
    0x00, 0x00, 0x60, 0x00, 0x9C, 0x00, 0x9C, 0x00, 0x60,             // 245
    0x00, 0x00, 0x64, 0x00, 0x90, 0x00, 0x90, 0x00, 0x64,             // 246
    0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0xA8, 0x00, 0x20, 0x00, 0x20, // 247
    0x00, 0x00, 0xF0, 0x00, 0xD0, 0x00, 0xB0, 0x00, 0xF0,             // 248
    0x00, 0x00, 0xF4, 0x00, 0x80, 0x00, 0x80, 0x00, 0xF0,             // 249
    0x00, 0x00, 0xF4, 0x00, 0x80, 0x00, 0x80, 0x00, 0xF0,             // 250
    0x00, 0x00, 0xF0, 0x00, 0x84, 0x00, 0x84, 0x00, 0xF0,             // 251
    0x00, 0x00, 0xF0, 0x00, 0x84, 0x00, 0x84, 0x00, 0xF0,             // 252
    0x00, 0x00, 0x14, 0x02, 0xE0, 0x03, 0x60, 0x00, 0x10,             // 253
    0x00, 0x00, 0xFE, 0x03, 0x90, 0x00, 0x90, 0x00, 0x60,             // 254
    0x00, 0x00, 0x14, 0x02, 0xE0, 0x03, 0x64, 0x00, 0x10              // 255
};

uint8_t const SPLASH_DATA[] PROGMEM = {
    0x00, 0xe0, 0x0f, 0x00, 0xf8, 0xf3, 0x9f, 0x1f, 0x48, 0xf2, 0x9f, 0x10,
    0x48, 0xf2, 0x9f, 0x10, 0x48, 0xf2, 0x9f, 0x10, 0x08, 0xf2, 0x1f, 0x0f,
    0x00, 0xf0, 0x1f, 0x00, 0x30, 0xf1, 0x9f, 0x1f, 0x48, 0xf2, 0x9f, 0x04,
    0x48, 0xf2, 0x9f, 0x04, 0x48, 0xf2, 0x9f, 0x04, 0x48, 0xf2, 0x1f, 0x1b,
    0x90, 0xf1, 0x1f, 0x00, 0x00, 0xf0, 0x9f, 0x1f, 0xf8, 0xf3, 0x1f, 0x00,
    0x48, 0xe0, 0x8f, 0x07, 0x48, 0xe0, 0x0f, 0x18, 0x48, 0xc0, 0x07, 0x18,
    0x30, 0xc0, 0x87, 0x07, 0x00, 0xc0, 0x07, 0x00, 0x00, 0xc0, 0x87, 0x1f,
    0x10, 0xc1, 0x87, 0x14, 0x48, 0xc2, 0x87, 0x14, 0x48, 0xc2, 0x87, 0x14,
    0xb0, 0xc1, 0x87, 0x10, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x80, 0x83, 0x1f,
    0x10, 0x83, 0x83, 0x04, 0x88, 0x82, 0x83, 0x04, 0x48, 0x02, 0x81, 0x04,
    0x30, 0x02, 0x01, 0x1b, 0x00, 0x00, 0x01, 0x00};
