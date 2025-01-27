#include "File.hpp"

#include "Engine/Engine.hpp"
#include "Files.hpp"

namespace acid {
File::File(std::filesystem::path filename, std::unique_ptr<Node> &&node) :
	m_filename(std::move(filename)),
	m_node(std::move(node)) {
}

void File::Load() {
#if defined(ACID_DEBUG)
	auto debugStart = Time::Now();
#endif

	if (Files::ExistsInPath(m_filename)) {
		IFStream inStream(m_filename);
		m_node->LoadStream(inStream);
	} else if (std::filesystem::exists(m_filename)) {
		std::ifstream inStream(m_filename);
		m_node->LoadStream(inStream);
		inStream.close();
	}

#if defined(ACID_DEBUG)
	Log::Out("File ", m_filename, " loaded in ", (Time::Now() - debugStart).AsMilliseconds<float>(), "ms\n");
#endif
}

void File::Write(Node::Format format) const {
#if defined(ACID_DEBUG)
	auto debugStart = Time::Now();
#endif

	if (Files::ExistsInPath(m_filename)) {
		OFStream os(m_filename);
		m_node->WriteStream(os, format);
	} else { // if (std::filesystem::exists(m_filename))
		if (auto parentPath = m_filename.parent_path(); !parentPath.empty()) {
			std::filesystem::create_directories(parentPath);
		}

		std::ofstream os(m_filename);
		m_node->WriteStream(os, format);
		os.close();
	}

#if defined(ACID_DEBUG)
	Log::Out("File ", m_filename, " saved in ", (Time::Now() - debugStart).AsMilliseconds<float>(), "ms\n");
#endif
}

void File::Clear() {
	m_node->Clear();
}
}
