[1, 2, 3, 4, 5, 6, 7, 0, 0, 0] ---> ;
[11, 2, 3, 4, 5, 6, 7, 8, 9, 10] ---> ;
[11, 12, 3, 4, 5, 6, 7, 8, 9, 10] ---> ;
-----------------------；
情形1;
[1, 2, 3, 4, somewhere, 5, 6, 7, 0, 0, 0] ---> ;
情形2;
[11, 12, 13, 14, 15, 16, 17, 8, somewhere, 9, 10] ---> ;
-----------------------
void adjustDistortion()
{
    while (imuPointerCur != imuPointerLast)
    {
        if (timeScanCur + pointTime < imuTime[imuPointerCur])
        {
            break;
        }
        imuPointerCur = (imuPointerCur + 1) % imuQueLength; // imuQueLength = 10;  情形1. imuPointerCur == 0; 情形2. imuPointerCur == 9;
    }

    if (timeScanCur + pointTime > imuTime[imuPointerCur])
    {
        //情形2, 此时 imuPointerCur ＝＝ imuPointerLast；
        imuRollCur = imuRoll[imuPointerCur];
        imuPitchCur = imuPitch[imuPointerCur];
        imuYawCur = imuYaw[imuPointerCur];
    } else { //情形1
        int imuPointerBack = (imuPointerCur + imuQueLength - 1) % imuQueLength;
        // imuQueLength = 10; 情形1, imuPointerCur = 0; 情形2, imuPointerCur = 5;
        float ratioFront = (timeScanCur + pointTime - imuTime[imuPointerBack])
            / (imuTime[imuPointerFront] - imuTime[imuPointerBack]);
        float ratioBack = (imuTime[imuPointerFront] - timeScanCur - pointTime)
            / (imuTime[imuPointerFront] - imuTime[imuPointerBack]);

        imuRollCur = imuRoll[imuPointerFront] * ratioFront + imuRoll[imuPointerBack] * ratioBack;
        imuPitchCur = imuPitch[imuPointerFront] * ratioFront + imuPitch[imuPointerBack] * ratioBack;
        if (imuYaw[imuPointerFront] - imuYaw[imuPointerBack] > M_PI) {
            imuYawCur = imuYaw[imuPointerFront] * ratioFront + (imuYaw[imuPointerBack] + 2 * M_PI) * ratioBack;
        } else if (imuYaw[imuPointerFront] - imuYaw[imuPointerBack] < -M_PI) {
            imuYawCur = imuYaw[imuPointerFront] * ratioFront + (imuYaw[imuPointerBack] - 2 * M_PI) * ratioBack;
        } else {
            imuYawCur = imuYaw[imuPointerFront] * ratioFront + imuYaw[imuPointerBack] * ratioBack;
        }
        //...
    }
