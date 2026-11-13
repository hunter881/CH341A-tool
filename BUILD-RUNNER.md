# Build CH341A Tool on a Windows runner

1. Set up a dedicated Windows x64 VM and install and activate C++Builder with Win32 VCL using a license suitable for that machine. Run the GitHub runner under the account that can use the activated compiler. Keep personal files and credentials off the build VM.
2. In C++Builder, migrate the legacy group to an MSBuild project group. Include the common and jsoncpp static libraries and the CH341A VCL application. Build the Win32 Release configuration once in the IDE. Confirm the EXE is named CH341A_tool.exe and its ProductVersion is 1.0.8a. Commit the migrated project files to the max7219-1.0.8a branch.
3. In the fork's Settings > Actions > Runners, add a self-hosted Windows x64 runner with the additional label ch341a-cppbuilder. Follow GitHub's generated setup instructions on the VM. Run the runner interactively first to use the same Windows profile as C++Builder.
4. In Settings > Secrets and variables > Actions > Variables, set RAD_STUDIO_ROOT to the C++Builder installation directory containing bin\rsvars.bat. Set CH341A_PROJECT to the repository-relative path to the migrated MSBuild project group, then set CH341A_RUNNER_READY to true.
5. Push to max7219-1.0.8a to trigger the build. Download CH341A-Tool-1.0.8a-Win32 from the successful run's Artifacts section. Test the seven-segment panel on the PC connected to the adapter.

GitHub's standard Windows image does not include the C++Builder VCL toolchain.
The workflow does not run on pull requests. Register the runner to this fork only.
