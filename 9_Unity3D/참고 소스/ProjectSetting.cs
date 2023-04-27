using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public enum REFRESHRATE
{
    UNLIMITED = 0,
    _30Hz = 30,
    _60Hz = 60,
    _75Hz = 75,
    _120Hz = 120,
    _144Hz = 144,
    _240Hz = 240,
}
public enum RESOLUTION { HD, FHD, WQHD, UHD_4K, UHD_5K, UHD_8K }
public enum AAMS { NONE = 0, x2 = 2, x4 = 4, x8 = 8, }
public enum QUALITY { NONE = -1, LOW, MEDIUM, HIGH, VERY_HIGH }

public static class ProjectSetting
{
    private static FullScreenMode screenMode = FullScreenMode.FullScreenWindow;

    /// <summary>
    /// ȭ�� ��� ����
    /// </summary>
    public static void SetScreenMode(FullScreenMode mode)
    {
        screenMode = mode;
        Screen.fullScreenMode = screenMode;
    }

    /// <summary>
    /// ȭ�� �ػ� ���� �� �ֻ��� ����
    /// </summary>
    public static void SetResolution(RESOLUTION resolution, REFRESHRATE refreshRate = REFRESHRATE.UNLIMITED)
    {
        int width, height;
        switch (resolution)
        {
            case RESOLUTION.HD: width = 1280; height = 720; break;
            case RESOLUTION.FHD: width = 1920; height = 1080; break;
            case RESOLUTION.WQHD: width = 2560; height = 1440; break;
            case RESOLUTION.UHD_4K: width = 3840; height = 2160; break;
            case RESOLUTION.UHD_5K: width = 5120; height = 2880; break;
            case RESOLUTION.UHD_8K: width = 7680; height = 4320; break;
            default: return;
        }

        Screen.SetResolution(width, height, screenMode, (int)refreshRate);
    }

    public static void SetFPS(int fps)
    {
        Application.targetFrameRate = fps;
    }

    /// <summary>
    /// ��Ƽ �ٸ����(��Ƽ���ø�)
    /// </summary>
    public static void SetAAMS(AAMS level)
    {
        QualitySettings.antiAliasing = (int)level;
    }

    /// <summary>
    /// ���漺 ���͸� : �񽺵��� ������ �ؽ�ó ǰ�� ����
    /// </summary>
    public static void SetAnisotropicFiltering(bool enable)
    {
        QualitySettings.anisotropicFiltering = (AnisotropicFiltering)(enable ? 1 : 0);
    }

    public static void SetShadowQuality(QUALITY level)
    {
        switch (level)
        {
            case QUALITY.NONE:
                QualitySettings.shadows = ShadowQuality.Disable;
                QualitySettings.shadowResolution = ShadowResolution.Low;
                break;

            default:
                QualitySettings.shadows = ShadowQuality.All;
                QualitySettings.shadowResolution = (ShadowResolution)level;
                break;
        }        
    }

    /// <summary>
    /// �Ӹ� ������ ����, 0:����, 1:1/2, 2:1/4
    /// </summary>
    public static void SetTextureQuality(int mipmapLevel)
    {
        mipmapLevel = Mathf.Clamp(mipmapLevel, 0, 2);
        QualitySettings.masterTextureLimit = mipmapLevel;
    }

    /// <summary>
    /// ��������ȭ
    /// </summary>
    public static void SetVSync(bool enable)
    {
        QualitySettings.vSyncCount = (enable ? 1 : 0);
    }
}
