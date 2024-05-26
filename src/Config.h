/*
obs-ndi
Copyright (C) 2016-2024 OBS-NDI Project <obsndi@obsndiproject.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>
*/
#pragma once

#include <QString>
#include <QVersionNumber>
#include <obs-module.h>

class Config {
public:
	static Config *Current();
	static bool VerboseLog();

	Config();
	void Load();
	void Save();

	bool OutputEnabled;
	QString OutputName;
	QString OutputGroups;
	bool PreviewOutputEnabled;
	QString PreviewOutputName;
	QString PreviewOutputGroups;
	bool TallyProgramEnabled;
	bool TallyPreviewEnabled;

	QString GetProgramGUID();
	bool AutoCheckForUpdates();
	void AutoCheckForUpdates(bool value);
	void SkipUpdateVersion(const QVersionNumber &version);
	QVersionNumber SkipUpdateVersion();

private:
	static Config *_instance;

	// Do not persist this to storage
	bool _VerboseLog;
};
