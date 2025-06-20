//
// Created by Alex on 20/06/2025.
//

#ifndef OPENGLBUFFER_H
#define OPENGLBUFFER_H


#include "Protea/Renderer/Buffer.h"

namespace Protea {
    class OpenGLVertexBuffer : public VertexBuffer {
    public:
        OpenGLVertexBuffer(float *vertices, uint32_t size);

        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const;

        virtual void Unbind() const;

    private:
        uint32_t m_RendererID;
    };

    class OpenGLIndexBuffer : public IndexBuffer {
    public:
        OpenGLIndexBuffer(uint32_t *indices, uint32_t count);

        virtual ~OpenGLIndexBuffer();

        virtual void Bind() const;

        virtual void Unbind() const;

        virtual uint32_t GetCount() const { return m_Count; }

    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };
}


#endif //OPENGLBUFFER_H
